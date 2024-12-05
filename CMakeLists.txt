cmake_minimum_required(VERSION 3.29)
project(ProjectDungeonDespoiler)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2)
find_package(SDL2_image)
find_package(SDL2_ttf)
find_package(OpenAL)
find_package(nlohmann_json)

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
        src/Engine/CreatureLoader.cpp
        src/Engine/Entity.cpp
        src/Engine/Entity.h
        src/Engine/Math.h
        src/Engine/Screen.h
        src/Engine/Screens/Map.cpp
        src/Engine/Screens/Map.h
)

target_link_libraries(ProjectDungeonDespoiler nlohmann_json::nlohmann_json OpenAL::OpenAL sdl_ttf::sdl_ttf SDL2_image::SDL2_image SDL2::SDL2main)
add_custom_command(
        TARGET ProjectDungeonDespoiler POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/resources
        $<TARGET_FILE_DIR:ProjectDungeonDespoiler>/resources
        USES_TERMINAL
)
