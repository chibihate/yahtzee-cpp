cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

project(src)

set(HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/Dice.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Category.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Game.h
)

set(SOURCE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Dice.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Category.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp
)

add_executable(yatzii ${HEADER} ${SOURCE} Main.cpp)
install(TARGETS yatzii DESTINATION bin)