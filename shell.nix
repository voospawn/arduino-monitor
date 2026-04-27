{ pkgs ? import <nixpkgs> { config.allowUnfree = true; programs.dconf.enable = true; services.dbus.enable = true; } }:

pkgs.mkShell {
  packages = with pkgs; [
    git
    python314
    pipx
    libgccjit
    gcc15
#     rocmPackages.llvm.clang-unwrapped
#     rocmPackages.clang
    qt6.qtbase
    qt6.qttools
    cmake
    ninja
    gnumake
    pkg-config
    alsa-lib
    alsa-lib.dev
    gcc
    qtcreator
    qt6.qtserialport
    qt6.qtsvg
    qt6.qtwayland
    qt6.qtdeclarative
    qt6.qtshadertools
    cudaPackages.cuda_nvml_dev
    cudaPackages.cudatoolkit
    arduino-ide

#     gnome fixes

#     glib
#     gtk3
#     gsettings-desktop-schemas
#     dconf
  ];

  nativeBuildInputs = [
    pkgs.cudaPackages.cudatoolkit
    pkgs.linuxPackages.nvidia_x11
  ];
}
