cmake_minimum_required(VERSION 3.0)

project("dbms" C CXX)

enable_testing()
include(Dart)

# Threads
find_package(Threads REQUIRED)

# Build flags
SET(EXECUTABLE_OUTPUT_PATH      "${PROJECT_BINARY_DIR}/bin")
SET(LIBRARY_OUTPUT_PATH         "${PROJECT_BINARY_DIR}/lib")

# Compile flags
execute_process(COMMAND getconf LEVEL1_DCACHE_LINESIZE
    OUTPUT_VARIABLE LEVEL1_DCACHE_LINESIZE
    OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND getconf PAGESIZE
    OUTPUT_VARIABLE PAGESIZE
    OUTPUT_STRIP_TRAILING_WHITESPACE)
SET(CMAKE_COMPILE_FLAGS         "-W -Wall -pedantic -DLEVEL1_DCACHE_LINESIZE=${LEVEL1_DCACHE_LINESIZE} -DPAGESIZE=${PAGESIZE} -march=native -ggdb")
SET(CMAKE_C_FLAGS               "${CMAKE_C_FLAGS} ${CMAKE_COMPILE_FLAGS}")
SET(CMAKE_CXX_FLAGS             "-std=c++17 ${CMAKE_CXX_FLAGS} ${CMAKE_COMPILE_FLAGS}")

add_custom_target(check COMMAND ctest --output-on-failure)

# Directories
include_directories(src/)
add_subdirectory(src/)
add_subdirectory(test/)
