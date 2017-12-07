cmake_minimum_required(VERSION 3.8)

project(lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        lab1/main.cpp
        LICENSE)

add_executable(labs_1 ${SOURCE_FILES})

project(lab2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        lab2/main.cpp
        LICENSE)

add_executable(labs_2 ${SOURCE_FILES})

project(lab3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        lab3/main.cpp
        LICENSE)

add_executable(labs_3 ${SOURCE_FILES})