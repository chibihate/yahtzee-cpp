cmake_minimum_required(VERSION 3.22)
project(test)

# Setup testing
enable_testing()
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/unittest)