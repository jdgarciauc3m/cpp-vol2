find_package(GTest REQUIRED)

include_directories(..)
add_executable(utest ut_vecvalues.cpp)
target_link_libraries(utest GTest::GTest GTest::Main)