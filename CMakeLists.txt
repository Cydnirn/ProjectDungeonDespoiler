cmake_minimum_required(VERSION 3.25)
project(ProjectDungeonDespoiler)

set(CMAKE_CXX_STANDARD 20)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

if(WIN32)
    set(CMAKE_GENERATOR "MinGW Makefiles")
else ()
    set(CMAKE_GENERATOR "Unix Makefiles")
endif()



add_executable(ProjectDungeonDespoiler src/main.cpp
        src/Utils/Creature.cpp
        src/Utils/Creature.h
        src/Utils/Game.cpp
        src/Utils/Game.h)

target_link_libraries(ProjectDungeonDespoiler ${CURSES_LIBRARIES})