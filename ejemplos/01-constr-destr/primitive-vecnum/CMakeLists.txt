cmake_minimum_required(VERSION 3.20)
project(primitive-vecnum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_executable(primitive_vecnum main.cpp)
