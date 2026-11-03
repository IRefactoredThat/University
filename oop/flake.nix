{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = {
    nixpkgs,
    self,
  }: let
    systems = ["x86_64-linux"];
    forAll = f: nixpkgs.lib.genAttrs systems (s: f nixpkgs.legacyPackages.${s});
  in {
    devShells = forAll (pkgs: {
      default = pkgs.mkShell.override {stdenv = pkgs.clangStdenv;} {
        packages = with pkgs; [cmake clang-tools just];
      };
    });
  };
}
