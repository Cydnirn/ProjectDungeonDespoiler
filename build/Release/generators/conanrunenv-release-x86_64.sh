script_folder="/home/rei/Programming/CPP/ProjectDungeonDespoiler/build/Release/generators"
echo "echo Restoring environment" > "$script_folder/deactivate_conanrunenv-release-x86_64.sh"
for v in ACLOCAL_PATH AUTOMAKE_CONAN_INCLUDES PATH M4 ALSA_CONFIG_DIR OPENSSL_MODULES
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "$script_folder/deactivate_conanrunenv-release-x86_64.sh"
    else
        echo unset $v >> "$script_folder/deactivate_conanrunenv-release-x86_64.sh"
    fi
done


export ACLOCAL_PATH="$ACLOCAL_PATH:/home/rei/.conan2/p/b/libto93bd03bccb121/p/res/aclocal"
export AUTOMAKE_CONAN_INCLUDES="$AUTOMAKE_CONAN_INCLUDES:/home/rei/.conan2/p/b/libto93bd03bccb121/p/res/aclocal"
export PATH="/home/rei/.conan2/p/autom480a421c82a75/p/bin:/home/rei/.conan2/p/autocf2af015330354/p/bin:/home/rei/.conan2/p/m43fe61932e2887/p/bin:$PATH"
export M4="/home/rei/.conan2/p/m43fe61932e2887/p/bin/m4"
export ALSA_CONFIG_DIR="/home/rei/.conan2/p/b/libalf4fc4264c2585/p/res/alsa"
export OPENSSL_MODULES="/home/rei/.conan2/p/b/opens536f29ab48795/p/lib/ossl-modules"