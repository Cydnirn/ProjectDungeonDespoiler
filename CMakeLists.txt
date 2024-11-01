cmake_minimum_required(VERSION 3.25)
project(ProjectDungeonDespoiler)

set(CMAKE_CXX_STANDARD 20)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
message(STATUS "Curses library found at ${CURSES_LIBRARIES}")


add_executable(ProjectDungeonDespoiler src/main.cpp
        src/Engine/Creature.cpp
        src/Engine/Creature.h
        src/Engine/Game.cpp
        src/Engine/Game.h
        src/Engine/Scene.cpp
        src/Engine/Scene.h)

target_link_libraries(ProjectDungeonDespoiler ${CURSES_LIBRARIES})