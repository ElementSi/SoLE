cmake_minimum_required(VERSION 3.23)
project(google-tests)
set(CMAKE_CXX_STANDARD 20)

add_executable(iteration_test iteration_test.cpp)

target_link_libraries(iteration_test source)