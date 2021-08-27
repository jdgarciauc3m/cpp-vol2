find_package(GTest REQUIRED)

add_executable(utest t_punto.cpp t_figura.cpp t_circulo.cpp t_rectangulo.cpp)
target_include_directories(utest PRIVATE ..)
target_link_libraries(utest GTest::GTest GTest::Main)