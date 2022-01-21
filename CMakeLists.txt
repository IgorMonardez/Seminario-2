cmake_minimum_required(VERSION 3.20)
project(Seminario-2 C)

set(CMAKE_C_STANDARD 99)

add_library(library library.c)
add_executable(main mainProfessor.c library)