cmake_minimum_required(VERSION 3.5.1)
project(union_find VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

enable_testing()

add_subdirectory(quick_find)
add_subdirectory(quick_union)
add_subdirectory(weighted_quick_union)
