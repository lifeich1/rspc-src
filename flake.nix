{
  inputs.utils.url = "github:numtide/flake-utils";

  outputs =
    {
      self,
      nixpkgs,
      utils,
    }:
    utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            just
            stdenv.cc.cc
            gnumake
          ];

          shellHook = ''
            export SHELL=zsh
            _rt=$(pwd)
            flags=()
            if [ -n "''${ODIR:-}" ]; then
              cd "$ODIR"
              if [ ! -f "main.cc" ]; then
                cat "$_rt/.tools/template.cc" > main.cc
              fi
              flags+=(main.cc)
            fi
            echo flags: ''${flags[*]}
            exec nvim -c "luaf $_rt/.tools/nvim.lua" \
              ''${flags[*]}
          '';
        };
      }
    );
}
