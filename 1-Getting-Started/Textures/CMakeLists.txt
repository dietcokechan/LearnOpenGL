cmake_minimum_required(VERSION 3.20)

link_libraries(OpenGL::GL glad glfw)

add_executable(Textures 
Textures.cpp 
ShaderClass.cpp 
VAO.cpp 
VBO.cpp
Includes/stb_image.cpp
)

add_subdirectory(Exercise)