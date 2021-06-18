cmake_minimum_required(VERSION 3.9)

project(${PROJECT_NAME} LANGUAGES CXX VERSION 1.0.0)

add_compile_options(-std=c++20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        istream_test
        test/istream_iter_test.cpp
)
target_include_directories(istream_test PRIVATE include)
target_link_libraries(
  istream_test
  gtest_main
  m
)

include(GoogleTest)
gtest_discover_tests(istream_test)

