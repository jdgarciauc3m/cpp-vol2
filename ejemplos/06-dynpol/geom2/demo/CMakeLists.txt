add_executable(demo main.cpp)
target_link_libraries(demo geom)
target_include_directories(demo PRIVATE ..)