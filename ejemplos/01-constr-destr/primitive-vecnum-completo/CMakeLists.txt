cmake_minimum_required(VERSION 3.20)
project(primitive-vecnum-completo
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(primitive_vecnum_completo main.cpp vecnum.cpp)
