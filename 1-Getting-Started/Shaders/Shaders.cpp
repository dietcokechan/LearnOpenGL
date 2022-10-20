#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shaders.h"
#include "ShaderClass.h"
#include "VAO.h"
#include "VBO.h"

int main()
{
    // Initializing GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // This means we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating GLFW window
    GLFWwindow *window = glfwCreateWindow(scr_width, scr_height, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initializing glad
    // Loading all opengl function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Specify OpenGl's viewport within the window
    glViewport(0, 0, 800, 600);

    // Vertices coordinates
    float vertices[] = {
        // Positions        // Colors
        0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,     // Top (red)
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // Bottom left (green)
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f     // Bottom right (blue)
    };

    // Generates Shader object using shaders from header file
    Shader shaderProgram(vertShaderPath, fragShaderPath);

    // Generates Vertex Array Object and binds it
    VAO VAO1;
    VAO1.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));

    // Links VBO to VAO
    VAO1.LinkVBO(VBO1, 0);
    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Input
        processInput(window);

        // Specify background color
        glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
        // Clean the back buffer and assign a new color to it
        glClear(GL_COLOR_BUFFER_BIT);

        // Pulsating green color
        // float time = glfwGetTime();
        // float green = (sin(time) / 2.0f) + 0.5f;
        // int vertexColorLocation = glGetUniformLocation(shaderProgram.ID, "myColor");

        // Tell OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // glUniform4f(vertexColorLocation, 0.0f, green, 0.0f, 1.0f);

        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();
    
        // Draw the triangle using OpenGL's primitive GL_TRIANGLES
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window);
        // Check and call GLFW events
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    shaderProgram.Delete();

    // Delete window and glfw before ending program
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

// Query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

// Whenever the window size changes (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}