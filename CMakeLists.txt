cmake_minimum_required(VERSION 3.29)
project(ProjectDungeonDespoiler)

set(CMAKE_CXX_STANDARD 20)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
message(STATUS "Curses library found at ${CURSES_LIBRARIES}")
message(STATUS "Curses include directory found at ${CMAKE_FIND_ROOT_PATH}")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/DungeonDespoiler)
add_executable(ProjectDungeonDespoiler src/main.cpp
        src/Engine/Creature.cpp
        src/Engine/Creature.h
        src/Engine/Game.cpp
        src/Engine/Game.h
        src/Engine/Scene.cpp
        src/Engine/Scene.h)

target_link_libraries(ProjectDungeonDespoiler ${CURSES_LIBRARIES})

if (WIN32)
    set(CURSES_DLLS
            "${CMAKE_FIND_ROOT_PATH}/bin/libncursesw6.dll"
            "${CMAKE_FIND_ROOT_PATH}/bin/libformw6.dll"
            "${CMAKE_FIND_ROOT_PATH}/bin/libmenuw6.dll"
            "${CMAKE_FIND_ROOT_PATH}/bin/libpanelw6.dll"
    )
    add_custom_command(
            TARGET ProjectDungeonDespoiler POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_RUNTIME_DLLS:ProjectDungeonDespoiler>
            ${CURSES_DLLS}
            $<TARGET_FILE_DIR:ProjectDungeonDespoiler>
            #${EXECUTABLE_OUTPUT_PATH}
            USES_TERMINAL
            COMMAND_EXPAND_LISTS
    )
endif()