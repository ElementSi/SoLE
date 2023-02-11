cmake_minimum_required(VERSION 3.23)
project(google-tests)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TRIDIAGONAL_TESTS
        tridiagonal_matrix_tests.cpp)
set(TRIDIAGONAL_HEADER
        ../tridiagonal_matrix/tridiagonal_matrix.h
        ../tridiagonal_matrix/tridiagonal_matrix.cpp
        ../tridiagonal_matrix/tridiagonal_matrix_solver.h
        ../tridiagonal_matrix/tridiagonal_matrix_solver.cpp)

add_library(tridiagonal_matrix STATIC ${TRIDIAGONAL_HEADER})
add_executable(google_tests_run ${TRIDIAGONAL_TESTS})

target_link_libraries(google_tests_run
        gtest
        gtest_main
        tridiagonal_matrix
        )