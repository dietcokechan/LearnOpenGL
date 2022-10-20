cmake_minimum_required(VERSION 3.20)

link_libraries(OpenGL::GL glad glfw)

add_executable(Exercise
    Shaders.cpp
    ShaderClass.cpp
    VAO.cpp
    VBO.cpp
)

file(RELATIVE_PATH rel ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(Shaders PROPERTIES FOLDER "${rel}")