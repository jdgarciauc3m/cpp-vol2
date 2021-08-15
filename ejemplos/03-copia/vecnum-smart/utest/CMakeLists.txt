find_package(GTest REQUIRED)

add_executable(utest vecnum_test.cpp ../vecnum.cpp)
target_link_libraries(utest GTest::GTest GTest::Main)
target_include_directories(utest PRIVATE ..)

gtest_discover_tests(utest)