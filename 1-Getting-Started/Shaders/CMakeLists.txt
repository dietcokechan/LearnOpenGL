cmake_minimum_required(VERSION 3.20)

link_libraries(OpenGL::GL glad glfw)

add_executable(Shaders 
Shaders.cpp 
ShaderClass.cpp 
VAO.cpp 
VBO.cpp 
)

add_subdirectory(Resources)
add_subdirectory(Exercise)