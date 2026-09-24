cmake_minimum_required(VERSION 3.5.0)
project(test_opengl VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
find_package(OpenMP REQUIRED)
find_package(MPI REQUIRED)

add_executable(test_opengl 
    src/main.cpp
    src/glad.h
    src/glad.c
    src/simple_triangle_example.h
    src/simple_triangle_example.cpp
    src/custom_multi_example.h
    src/custom_multi_example.cpp
    src/glm/glm.hpp
    src/glm/gtc/matrix_transform.hpp
    src/glm/gtc/type_ptr.hpp
)

target_link_libraries(test_opengl 
    glfw
    OpenGL::GL
    OpenMP::OpenMP_CXX
    MPI::MPI_CXX
)