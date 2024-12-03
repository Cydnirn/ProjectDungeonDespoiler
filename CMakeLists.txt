cmake_minimum_required(VERSION 3.29)
project(ProjectDungeonDespoiler)

set(CMAKE_CXX_STANDARD 20)

find_package(pdcurses)
find_package(nlohmann_json)

#include_directories(${PDCURSES_INCLUDE_DIR})
#include_directories(${nlohmann_json_INCLUDE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/DungeonDespoiler)
add_executable(ProjectDungeonDespoiler src/main.cpp
        src/Engine/Creature.cpp
        src/Engine/Creature.h
        src/Engine/Game.cpp
        src/Engine/Game.h
        src/Engine/Scene.cpp
        src/Engine/Scene.h
        src/Engine/ScreenManager.cpp
        src/Engine/ScreenManager.h
        src/Creatures/CreatureLoader.cpp
)

target_link_libraries(ProjectDungeonDespoiler nlohmann_json::nlohmann_json pdcurses::pdcurses)


# if (WIN32)
#     set(CURSES_DLLS
#             "${CMAKE_FIND_ROOT_PATH}/bin/libncursesw6.dll"
#             "${CMAKE_FIND_ROOT_PATH}/bin/libformw6.dll"
#             "${CMAKE_FIND_ROOT_PATH}/bin/libmenuw6.dll"
#             "${CMAKE_FIND_ROOT_PATH}/bin/libpanelw6.dll"
#     )
#     add_custom_command(
#             TARGET ProjectDungeonDespoiler POST_BUILD
#             COMMAND ${CMAKE_COMMAND} -E copy
#             $<TARGET_RUNTIME_DLLS:ProjectDungeonDespoiler>
#             ${CURSES_DLLS}
#             $<TARGET_FILE_DIR:ProjectDungeonDespoiler>
#             USES_TERMINAL
#             COMMAND_EXPAND_LISTS
#     )
# endif()
