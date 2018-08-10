cmake_minimum_required(VERSION 3.5.1)
project(union_find VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
