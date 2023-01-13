cmake_minimum_required(VERSION 3.23)
project(ex_0 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ex_0
        ADTStack.c
        ADTStack.h
        main.c)
