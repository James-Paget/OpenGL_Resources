cmake_minimum_required(VERSION 3.5.0)
project(test_opengl VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(test_opengl 
    src/main.cpp
    src/glad.h
    src/glad.c
)

target_link_libraries(test_opengl 
    glfw
    OpenGL::GL
)