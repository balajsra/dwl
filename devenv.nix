{ pkgs, lib, config, inputs, ... }:

{
  # https://devenv.sh/packages/
  packages = [
      pkgs.git
      pkgs.yaml-language-server
      pkgs.gdb
  ];

  # https://devenv.sh/languages/
  languages.c = {
    enable = true;
    debugger = pkgs.gdb;
  };
  languages.cplusplus = {
    enable = true;
  };
}
