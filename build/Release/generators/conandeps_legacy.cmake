message(STATUS "Conan: Using CMakeDeps conandeps_legacy.cmake aggregator via include()")
message(STATUS "Conan: It is recommended to use explicit find_package() per dependency instead")

find_package(OpenAL)
find_package(SDL2_ttf)
find_package(SDL2_image)
find_package(SDL2)
find_package(pdcurses)
find_package(nlohmann_json)

set(CONANDEPS_LEGACY  OpenAL::OpenAL  sdl_ttf::sdl_ttf  SDL2_image::SDL2_image  SDL2::SDL2main  pdcurses::pdcurses  nlohmann_json::nlohmann_json )