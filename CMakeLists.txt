cmake_minimum_required(VERSION 3.23)
project(SoLE)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE main.cpp)
set(HEADER tridiagonal_matrix/tridiagonal_matrix.h
           tridiagonal_matrix/tridiagonal_matrix.cpp
           tridiagonal_matrix/tridiagonal_matrix_solver.h
           tridiagonal_matrix/tridiagonal_matrix_solver.cpp)

add_executable(main ${SOURCE})
add_library(tridiagonal_matrix STATIC ${HEADER})

target_link_libraries(main tridiagonal_matrix)

add_subdirectory(google-tests)
