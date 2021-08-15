cmake_minimum_required(VERSION 3.20)
project(vecnum_nocopy)

set(CMAKE_CXX_STANDARD 20)

add_executable(vecnum_nocopy main.cpp vecnum.cpp vecnum.hpp)
