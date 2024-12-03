# Project Dungeon Despoiler

## Description

Project Tugas Akhir kelas Bachelor Informatics dari Universitas Amikom Yogyakarta
untuk mata kuliah Algorithm & Programming. Project ini merupakan game berbasis text yang 
bertujuan untuk mengalahkan monster-monster yang ada di dalam dungeon. 
Game ini dibuat menggunakan bahasa pemrograman C++.

## How to Build

Dependencies:
- CMake
- C++ Compiler
- Conan
- pdcurses
- nlohmann_json

### How to Build dependencies

Pastikan Conan sudah terinstall di komputer anda. Jika belum, silahkan install Conan terlebih dahulu.


1. Jalankan deteksi profile Conan
```bash
conan profile detect
```

2. Install dependencies
```bash
conan install . --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
```

3. Build Project
```bash
cmake . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=/path/to/conan/build/Release/generators/conan_toolchain.cmake
 
```