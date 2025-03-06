cmake_minimum_required(VERSION 3.10)
project(first_game VERSION 0.1.0)

add_executable(first_game src/main.cpp src/glad.h src/glad.c)

target_link_libraries( first_game glfw )