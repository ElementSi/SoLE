cmake_minimum_required(VERSION 3.23)
project(google-tests)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE TESTS "*.cpp")

add_executable(google_tests_run ${TESTS})

target_link_libraries(google_tests_run
        gtest
        gtest_main
        tridiagonal_matrix
        )