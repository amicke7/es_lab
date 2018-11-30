cmake_minimum_required(VERSION 3.8)
project(es_lab_programmazione)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES
        main.cpp
        MatrixFactory.h
        MatrixTemplate.h)

add_executable(p ${SOURCE_FILES})