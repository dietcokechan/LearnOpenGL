cmake_minimum_required(VERSION 3.20)

include(FetchContent)

# OpenGL
find_package(OpenGL REQUIRED)

# GLAD
FetchContent_Declare(glad
    GIT_REPOSITORY git@github.com:Dav1dde/glad.git
    GIT_TAG        v0.1.36
)
FetchContent_MakeAvailable(glad)

# GLFW
FetchContent_Declare(glfw
    GIT_REPOSITORY git@github.com:glfw/glfw.git
    GIT_TAG 3.3.8
)
FetchContent_MakeAvailable(glfw)
option(GLFW_BUILD_EXAMPLES OFF) # Disabling additional build targets
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_DOCS OFF)
option(GLFW_INSTALL OFF)
option(GLFW_VULKAN_STATIC OFF)

project(LearnOpenGL)

add_subdirectory(1-Getting-Started)
