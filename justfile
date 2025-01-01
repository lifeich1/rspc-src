paste-as-dir: && (dir `wl-paste`)
  wl-paste
  wl-paste | perl -p -e 'die unless /\A(abc|arc|)\d+\/\w+\Z/'

dir odir:
  mkdir -p {{ odir }}
  ODIR={{ odir }} nix develop

dir-ctx prog: && (dir (`cat current-context` + "/" + prog))
  test -f current-context
  test -n "$(cat current-context)"

ctx name:
  echo "{{ name }}" > ./current-context


a: (dir-ctx "a")
b: (dir-ctx "b")
c: (dir-ctx "c")
d: (dir-ctx "d")
e: (dir-ctx "e")
f: (dir-ctx "f")
g: (dir-ctx "g")
h: (dir-ctx "h")
i: (dir-ctx "i")
j: (dir-ctx "j")
k: (dir-ctx "k")



tada:
	./.tools/prepare-msg.pl tada

ac:
	./.tools/prepare-msg.pl ac

ar ctx=`cat current-context`:
  git mv {{ ctx }} _archive/
  git commit -a -m ":truck: _archive {{ ctx }}, close #`perl ./.tools/archive_contest_issue.pl {{ ctx }}`" -e
  rm -f current-context

