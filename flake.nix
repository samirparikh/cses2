{
  description = "CSES problem set solutions in C";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }:
    let
      forAllSystems = nixpkgs.lib.genAttrs [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];
    in {
      devShells = forAllSystems (system:
        let pkgs = nixpkgs.legacyPackages.${system};
        in {
          default = pkgs.mkShell {
            packages = [ pkgs.gcc ];
            # Auto-inject `-I<repo>/lib` so a plain `gcc file.c` inside the
            # devShell picks up shared headers (e.g. compare_ints.h) without
            # a relative include path. nixpkgs wraps gcc to prepend
            # NIX_CFLAGS_COMPILE to every invocation, so this works even when
            # your command doesn't reference $CFLAGS. Assumes you entered the
            # shell (via `nix develop` or direnv's `use flake`) from the repo
            # root, which is the normal case.
            shellHook = ''
              export NIX_CFLAGS_COMPILE="-I$PWD/lib ''${NIX_CFLAGS_COMPILE:-}"
            '';
          };
        });
    };
}
