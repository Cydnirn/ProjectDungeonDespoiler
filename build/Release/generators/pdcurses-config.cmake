########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(pdcurses_FIND_QUIETLY)
    set(pdcurses_MESSAGE_MODE VERBOSE)
else()
    set(pdcurses_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/pdcursesTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${pdcurses_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(pdcurses_VERSION_STRING "3.9")
set(pdcurses_INCLUDE_DIRS ${pdcurses_INCLUDE_DIRS_RELEASE} )
set(pdcurses_INCLUDE_DIR ${pdcurses_INCLUDE_DIRS_RELEASE} )
set(pdcurses_LIBRARIES ${pdcurses_LIBRARIES_RELEASE} )
set(pdcurses_DEFINITIONS ${pdcurses_DEFINITIONS_RELEASE} )


# Only the last installed configuration BUILD_MODULES are included to avoid the collision
foreach(_BUILD_MODULE ${pdcurses_BUILD_MODULES_PATHS_RELEASE} )
    message(${pdcurses_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


