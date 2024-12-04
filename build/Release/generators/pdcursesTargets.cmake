# Load the debug and release variables
file(GLOB DATA_FILES "${CMAKE_CURRENT_LIST_DIR}/pdcurses-*-data.cmake")

foreach(f ${DATA_FILES})
    include(${f})
endforeach()

# Create the targets for all the components
foreach(_COMPONENT ${pdcurses_COMPONENT_NAMES} )
    if(NOT TARGET ${_COMPONENT})
        add_library(${_COMPONENT} INTERFACE IMPORTED)
        message(${pdcurses_MESSAGE_MODE} "Conan: Component target declared '${_COMPONENT}'")
    endif()
endforeach()

if(NOT TARGET pdcurses::pdcurses)
    add_library(pdcurses::pdcurses INTERFACE IMPORTED)
    message(${pdcurses_MESSAGE_MODE} "Conan: Target declared 'pdcurses::pdcurses'")
endif()
# Load the debug and release library finders
file(GLOB CONFIG_FILES "${CMAKE_CURRENT_LIST_DIR}/pdcurses-Target-*.cmake")

foreach(f ${CONFIG_FILES})
    include(${f})
endforeach()