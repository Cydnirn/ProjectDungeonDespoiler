# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(pdcurses_FRAMEWORKS_FOUND_RELEASE "") # Will be filled later
conan_find_apple_frameworks(pdcurses_FRAMEWORKS_FOUND_RELEASE "${pdcurses_FRAMEWORKS_RELEASE}" "${pdcurses_FRAMEWORK_DIRS_RELEASE}")

set(pdcurses_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET pdcurses_DEPS_TARGET)
    add_library(pdcurses_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET pdcurses_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Release>:${pdcurses_FRAMEWORKS_FOUND_RELEASE}>
             $<$<CONFIG:Release>:${pdcurses_SYSTEM_LIBS_RELEASE}>
             $<$<CONFIG:Release>:xorg::xorg>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### pdcurses_DEPS_TARGET to all of them
conan_package_library_targets("${pdcurses_LIBS_RELEASE}"    # libraries
                              "${pdcurses_LIB_DIRS_RELEASE}" # package_libdir
                              "${pdcurses_BIN_DIRS_RELEASE}" # package_bindir
                              "${pdcurses_LIBRARY_TYPE_RELEASE}"
                              "${pdcurses_IS_HOST_WINDOWS_RELEASE}"
                              pdcurses_DEPS_TARGET
                              pdcurses_LIBRARIES_TARGETS  # out_libraries_targets
                              "_RELEASE"
                              "pdcurses"    # package_name
                              "${pdcurses_NO_SONAME_MODE_RELEASE}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${pdcurses_BUILD_DIRS_RELEASE} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Release ########################################
    set_property(TARGET pdcurses::pdcurses
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Release>:${pdcurses_OBJECTS_RELEASE}>
                 $<$<CONFIG:Release>:${pdcurses_LIBRARIES_TARGETS}>
                 )

    if("${pdcurses_LIBS_RELEASE}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET pdcurses::pdcurses
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     pdcurses_DEPS_TARGET)
    endif()

    set_property(TARGET pdcurses::pdcurses
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Release>:${pdcurses_LINKER_FLAGS_RELEASE}>)
    set_property(TARGET pdcurses::pdcurses
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Release>:${pdcurses_INCLUDE_DIRS_RELEASE}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET pdcurses::pdcurses
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Release>:${pdcurses_LIB_DIRS_RELEASE}>)
    set_property(TARGET pdcurses::pdcurses
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Release>:${pdcurses_COMPILE_DEFINITIONS_RELEASE}>)
    set_property(TARGET pdcurses::pdcurses
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Release>:${pdcurses_COMPILE_OPTIONS_RELEASE}>)

########## For the modules (FindXXX)
set(pdcurses_LIBRARIES_RELEASE pdcurses::pdcurses)
