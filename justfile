dir odir:
  mkdir -p {{ odir }}
  ODIR={{ odir }} nix develop

alias d := dir
