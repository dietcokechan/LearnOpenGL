cmake_minimum_required(VERSION 3.20)

link_libraries(OpenGL::GL glad glfw)

add_executable(Transformations 
Transformations.cpp 
ShaderClass.cpp 
VAO.cpp 
VBO.cpp
Includes/stb_image.cpp
)