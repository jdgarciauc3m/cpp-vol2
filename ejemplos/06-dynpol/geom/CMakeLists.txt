cmake_minimum_required(VERSION 3.20)
project(geom)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

set(GEOM_HEADERS figura.hpp circulo.hpp)
set(GEOM_SRC figura.cpp circulo.cpp)
add_library(geom ${GEOM_SRC} ${GEOM_HEADERS})

link_libraries(geom)
add_subdirectory(demo)
add_subdirectory(utest)
