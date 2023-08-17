cmake_minimum_required(VERSION 3.23)
project(source)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE
        "*.h"
        "*.cpp")

add_library(source STATIC ${SOURCE} iterative_methods/iterative_methods.cpp)