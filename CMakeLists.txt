cmake_minimum_required(VERSION 2.6)
project(cpp_script)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_BINARY_DIR}/../src)
include_directories(${CMAKE_BINARY_DIR}/../include)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -Wpedantic")
file(
   GLOB_RECURSE
   srcFiles
   ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
add_executable(
   main
   ${srcFiles}
)

