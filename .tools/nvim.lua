vim.o.makeprg = "g++ -o %.exe -std=c++20 -Wall -g %";

local set_label = function(name, label)
end

local task_diff = function(name, out, ans)
end

local task_run = function()
  -- fetch name from cursor line, emit async run|diff|set_label
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

vim.keymap.set('n', '<leader>tc', function()
  vim.cmd("sp new|resize 10|file [Testcases]");
  vim.bo.buftype = 'nofile';
  vim.bo.bufhidden = 'hide';
  vim.bo.swapfile = false;
  vim.bo.readonly = true;
  update_tlwin();
  vim.keymap.set('n', 'u', update_tlwin, { buffer = true });
  vim.keymap.set('n', '<cr>', task_run, { buffer = true });
  -- edit in 'e
  -- edit ans 'E
  -- float show diff 'd
  -- test all 'a
end);
