cmake_minimum_required(VERSION 3.20)

link_libraries(OpenGL::GL glad glfw)

add_executable(Source Source.cpp)

file(RELATIVE_PATH rel ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(Source PROPERTIES FOLDER "${rel}")