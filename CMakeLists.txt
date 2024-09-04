cmake_minimum_required(VERSION 3.27)
project(Homework_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(main
        main.c
        movie.jlemahie.c
        movie.jlemahie.h)

add_executable(test
       warmup-units-tests.c
        movie.jlemahie.c
        movie.jlemahie.h)

