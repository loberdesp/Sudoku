cmake_minimum_required(VERSION 3.22)
# Tu wstawcie nazwę swojego projektu
project (Sudoku)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )


find_library(SDL2 NAMES "SDL2")
find_library(SDL2main NAMES "SDL2main")
find_library(SDL2_image NAMES "SDL2_image")
find_library(SDL2_ttf NAMES "SDL2_ttf")

set(SOURCE_FILES main.cpp game.cpp TextureManager.cpp)

# tu ustawiacie nazwę pliku wykonywalnego - możecie zmienić choinka na coś innego
add_executable(Sudoku ${SOURCE_FILES})
target_link_libraries(Sudoku SDL2 SDL2_image SDL2_ttf)