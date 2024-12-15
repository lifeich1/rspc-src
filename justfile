paste-as-dir: && (dir `wl-paste`)
  wl-paste
  wl-paste | perl -p -e 'die unless /\A(abc|arc|)\d+\/\w+\Z/'

dir odir:
  mkdir -p {{ odir }}
  ODIR={{ odir }} nix develop

alias d := dir
