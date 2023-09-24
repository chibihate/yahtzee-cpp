cmake_minimum_required(VERSION 3.22)
project(unittest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Set the compiler options
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

set(SOURCE
    ${src_SOURCE_DIR}/Dice.cpp
)

set(HEADER
    ${src_SOURCE_DIR}/Dice.h
)

set(TEST_FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/TestDice.cpp
)

include_directories(${src_SOURCE_DIR})

add_executable(
  unittest
  ${HEADER}
  ${SOURCE}
  ${TEST_FILE}
)

target_link_libraries(
  unittest
  gtest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(unittest)