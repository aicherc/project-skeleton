project(cython-tutorial)
cmake_minimum_required(VERSION 2.8.12)

# Set compiler flags
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

# Tests with CTEST
include(CTest)

# Add "_d" to binaries in debug mode
if (CMAKE_BUILD_TYPE STREQUAL Debug)
    set(BUILD_POSTFIX "_d")
else(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(BUILD_POSTFIX "")
endif(CMAKE_BUILD_TYPE STREQUAL Debug)

# Include directories with headers
include_directories(src)

# Add sub-directories with CMakeLists.txt
add_subdirectory(src)
add_subdirectory(test)

