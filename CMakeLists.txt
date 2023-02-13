cmake_minimum_required(VERSION 3.23)
project(SoLE)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(google-tests)

file(GLOB_RECURSE TRIDIAGONAL_MATRIX
        "tridiagonal_matrix/*.h"
        "tridiagonal_matrix/*.cpp")

add_library(tridiagonal_matrix STATIC ${TRIDIAGONAL_MATRIX})

add_executable(main main.cpp)