cmake_minimum_required(VERSION 3.20)

link_libraries(OpenGL::GL glad glfw)

add_executable(Exercise1 Exercise1.cpp)
add_executable(Exercise2 Exercise2.cpp)
add_executable(Exercise3 Exercise3.cpp)

file(RELATIVE_PATH rel ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(Exercise1 Exercise2 Exercise3 PROPERTIES FOLDER "${rel}")