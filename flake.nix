{
  description = "A dynamic tiling Wayland compositor using wlroots";

  outputs = {self}: {
    overlay = final: prev: {
      toml = prev.stdenv.mkDerivation {
        name = "tomlc99";
        version = "4e7b082";

        nativeBuildInputs = [
          prev.pkg-config
        ];

        src = prev.fetchFromGitHub {
          owner = "cktan";
          repo = "tomlc99";
          rev = "4e7b082ccc44316f212597ae5b09a35cf9329e69";
          hash = "sha256-R9OBMG/aUa80Qw/zqaks63F9ybQcThfOYRsHP4t1Gv8=";
        };

        buildPhase = ''
          make prefix="$out"
        '';

        installPhase = ''
          make install prefix="$out"

          mkdir -p "$out/lib/pkgconfig"

          substituteInPlace libtoml.pc.sample \
            --replace '/usr/local' "$out" \
            --replace 'libtoml' 'toml'

          mv libtoml.pc.sample "$out/lib/pkgconfig/toml.pc"
        '';
      };

      vivarium = prev.stdenv.mkDerivation {
        name = "vivarium";
        src = ./.;

        nativeBuildInputs = with final; [
          meson
          ninja
          pkg-config
          toml
        ];

        buildInputs = with final; [
          wlroots
          wayland
          wayland-protocols
          libxkbcommon
          udev.dev
          xorg.libxcb
          libxkbcommon
          libinput
          libdrm
          pixman
        ];

        # remove test dependecies
        # and turn off Werror, since it current causes build to fail
        postPatch = ''
          sed -i \
            -e '/^fff_dep/d' \
            -e '/^unity_dep/d' \
            -e '/^subdir.*tests/d' \
            -e '/werror=true/d' \
            meson.build

          rm -rf tests
        '';

        postInstall = ''
          mkdir -p "$out/share/wayland-sessions"

          cat << EOF > "$out/share/wayland-sessions/vivarium.desktop"
          [Desktop Entry]
          Name=Vivarium
          Comment=A dynamic tiling Wayland compositor using wlroots
          Exec=vivarium
          Type=Application
          EOF
        '';

        passthru.providedSessions = ["vivarium"];
      };
    };
  };
}
