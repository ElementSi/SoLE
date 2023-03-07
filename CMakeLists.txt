cmake_minimum_required(VERSION 3.23)
project(SoLE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(practical-tests)
add_subdirectory(google-tests)
add_subdirectory(source)