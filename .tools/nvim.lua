local set_label = function(buf, name, label)
  local tag = name:gsub("(.+)%.in", "^%%[case%%] %1\t");
  for i = 1, 200 do
    local text = vim.fn.getbufoneline(buf, i);
    if text:len() == 0 then
      break
    end
    if text:match(tag) ~= nil then
      local new_text = text:gsub("\t%w+$", "\t" .. label);
      vim.fn.setbufvar(buf, "&readonly", 0);
      vim.fn.setbufline(buf, i, new_text);
      vim.fn.setbufvar(buf, "&readonly", 1);
      break;
    end
  end
end

local task_diff = function(name, out, ans)
  local buf = vim.fn.bufnr();
  vim.system({ 'diff', '-q', '--ignore-trailing-space', '--ignore-blank-lines', out, ans }, {},
    vim.schedule_wrap(function(complete)
      local label = 'WA';
      if complete.code == 0 then
        label = 'AC';
      end
      set_label(buf, name, label);
    end));
end

local extract_testcase = function()
  local text = vim.fn.getline(vim.fn.line('.'));
  local case = text:match('^%[case%] (%w+)\t');
  if case == nil then
    vim.notify('Cannot extract testcase name from current line!', vim.log.levels.ERROR);
  end
  return case;
end

local task_run = function()
  -- fetch name from cursor line, emit async run|diff|set_label
  local case = extract_testcase();
  if case == nil then
    return;
  end
  local buf = vim.fn.bufnr();
  if vim.fn.filereadable('./main.cc.exe') == 0 then
    set_label(buf, case .. '.in', 'CE');
    return;
  end
  local input = case .. '.in';
  local out = case .. '.out';
  vim.print('running main.cc.exe');
  vim.system({ 'sh', '-c', string.format('./main.cc.exe < %s > %s', input, out) }, {},
    vim.schedule_wrap(function(complete)
      vim.print('done execute main.cc.exe');
      if complete.code == 0 then
        local ans = case .. '.ans';
        if vim.fn.filereadable(ans) then
          task_diff(input, out, ans);
        else
          set_label(buf, input, 'RAN');
        end
      else
        set_label(buf, input, 'RE');
      end
    end)
  );
end

local update_tlwin = function()
  vim.bo.readonly = false;
  local rec_line = vim.fn.line('.');
  vim.cmd("%d");
  for name, typ in vim.fs.dir('.') do
    if name:match('.*%.in$') and typ == 'file' then
      local out = name:gsub('%.in$', '.out');
      local ans = name:gsub('%.in$', '.ans');
      local have_out = vim.fn.filereadable(out);
      local have_ans = vim.fn.filereadable(ans);
      local label = "_";
      if have_out ~= 0 and have_ans ~= 0 then
        label = "diffing";
        task_diff(name, out, ans);
      elseif have_ans ~= 0 then
        label = "PENDING";
      elseif have_out ~= 0 then
        label = "RAN";
      end
      local text = string.gsub("$name\t$label", '%$(%w+)', {
        label = label, name = name:gsub("(.+)%.in", "[case] %1"),
      });
      vim.fn.append(0, text);
    end
  end
  vim.bo.readonly = true;
  vim.fn.cursor(rec_line, 0);
end

local edit_ext = function(suffix)
  local case = extract_testcase();
  if case == nil then
    return;
  end
  vim.cmd(string.format('edit %s.%s', case, suffix));
end

local rev = 4;

local makefile = string.format('/tmp/_rspc.mak.%d', rev);
local makefile_text = [[
main.cc.exe: main.cc
	g++ -o $@ -std=c++20 -Wall -g $<
]];
local justfile = string.format('/tmp/_rspc.just.%d', rev);
local justfile_text = [[
build:
  make -f %s

checkall: build
  #!/usr/bin/env bash
  set -euxo pipefail
  for i in *.in; do
    o=${i/%%in/out}
    timeout 5 ./main.cc.exe < $i > $o
    ans=${i/%%in/ans}
    if [ -f "$ans" ]; then
      diff -q --ignore-trailing-space --ignore-blank-lines "$o" "$ans"
    fi
  done

pwd:
  pwd
]];
justfile_text = justfile_text:format(makefile);

local setup_file = function(filename, text)
  if vim.fn.filereadable(filename) == 0 then
    local outf = io.open(filename, 'w');
    if outf ~= nil then
      outf:write(text);
      outf:flush();
      outf:close();
    else
      vim.notify('write failed! file: ' .. filename, vim.log.levels.ERROR);
    end
  end
end

setup_file(makefile, makefile_text);
setup_file(justfile, justfile_text);

local testcase_hl = function()
  vim.fn.matchadd('Include', '\\[case\\]');
  vim.fn.matchadd('Added', 'AC');
  vim.fn.matchadd('Todo', 'PENDING');
  vim.fn.matchadd('Changed', 'RAN');
  vim.fn.matchadd('Error', 'WA');
  vim.fn.matchadd('Error', 'RE');
end


vim.o.makeprg = string.format("just -f %s -d .", justfile);

vim.keymap.set('n', '<leader>tc', function()
  local src_buf = vim.fn.bufnr();
  if vim.t.case_buf ~= nil then
    local case_buf_toggle = vim.t.case_buf_toggle;
    vim.t.case_buf_toggle = 1;
    if case_buf_toggle == 1 then
      vim.cmd(string.format('buffer %d', vim.t.case_buf))
      vim.cmd('quit');
      vim.cmd(string.format('buffer %d', src_buf))
      vim.t.case_buf_toggle = 0;
    else
      vim.cmd(string.format('sbuffer %d|resize 10', vim.t.case_buf))
      testcase_hl();
    end
    return
  end
  vim.t.case_buf_toggle = 1;
  vim.cmd("sp new|resize 10|file [Testcases]");
  local case_buf = vim.fn.bufnr();
  vim.t.src_buf = src_buf;
  vim.t.case_buf = case_buf;

  vim.bo.buftype = 'nofile';
  vim.bo.bufhidden = 'hide';
  vim.bo.swapfile = false;
  vim.bo.readonly = true;
  vim.bo.makeprg = string.format("just -f %s checkall -d .", justfile);
  vim.api.nvim_create_autocmd('BufWinLeave', {
    pattern = '<buffer>',
    callback = function()
      vim.t.case_buf_toggle = 0;
    end,
  });
  update_tlwin();
  testcase_hl();

  vim.keymap.set('n', '<leader>tc', ':q<cr>', { buffer = true });
  vim.keymap.set('n', 'u', update_tlwin, { buffer = true });
  vim.keymap.set('n', '<cr>', task_run, { buffer = true });
  vim.keymap.set('n', 'e', function()
    edit_ext('in')
  end, { buffer = true });
  vim.keymap.set('n', 'E', function()
    edit_ext('ans')
  end, { buffer = true });
  vim.keymap.set('n', 'ge', function()
    edit_ext('out')
    vim.bo.readonly = true;
  end, { buffer = true });
  -- TODO float show diff 'd
end);
