/*
Exercise 3:
Create two shader programs where the second program uses a different fragment shader
that outputs the color yellow; draw both triangles again where one outputs the color yellow.
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int scr_width = 800;
const unsigned int scr_height = 600;

// shader sources
static const char *vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
)";

static const char *fragmentShaderSource_w = R"(
#version 330 core
out vec4 FragColor;
void main()
{
   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
)";

static const char *fragmentShaderSource_b = R"(
#version 330 core
out vec4 FragColor;
void main()
{
   FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
}
)";

int main()
{
    // Initializing GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // This means we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating GLFW window
    GLFWwindow* window = glfwCreateWindow(scr_width, scr_height, "LearnOpenGL", NULL, NULL);
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

    // Create Vertex Shader Object and get its reference
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader_w = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint fragmentShader_b = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint shaderProgram_w = glCreateProgram();
    GLuint shaderProgram_b = glCreateProgram();

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    glShaderSource(fragmentShader_w, 1, &fragmentShaderSource_w, NULL);
    glCompileShader(fragmentShader_w);

    glShaderSource(fragmentShader_b, 1, &fragmentShaderSource_b, NULL);
    glCompileShader(fragmentShader_b);

    glAttachShader(shaderProgram_w, vertexShader);
    glAttachShader(shaderProgram_w, fragmentShader_w);
    glLinkProgram(shaderProgram_w);

    glAttachShader(shaderProgram_b, vertexShader);
    glAttachShader(shaderProgram_b, fragmentShader_b);
    glLinkProgram(shaderProgram_b);

    // Delete the now useless Vertex and Fragment Shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader_w);
    glDeleteShader(fragmentShader_b);

    // Vertices coordinates
    float first_triangle[] = {
        -0.5f, 0.5f, 0.0f,
        -0.8f, -0.3f, 0.0f,
        -0.2f, -0.3f, 0.0f
    };

    float second_triangle[] = {
        0.5f, 0.5f, 0.0f,
        0.2f, -0.3f, 0.0f,
        0.8f, -0.3f, 0.0f
    };

    // Create reference containers for the Vartex Array Object and the Vertex Buffer Object
    GLuint VAO[2], VBO[2]; // Note that VAO must be initialized before VBO
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);

    // First triangle
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(first_triangle), first_triangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Second triangle
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(second_triangle), second_triangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Input
        processInput(window);

        // Specify background color
        glClearColor(0.6f, 0.4f, 0.5f, 1.0f);
        // Clean the back buffer and assign a new color to it
        glClear(GL_COLOR_BUFFER_BIT);

        // Use shader program
        glUseProgram(shaderProgram_w);
        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram_b);
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window);
        // Check and call GLFW events
        glfwPollEvents();
    }

    // Delete objects created
    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(2, VBO);
    glDeleteProgram(shaderProgram_w);
    glDeleteProgram(shaderProgram_b);

    // Delete window and glfw before ending program
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

// Query GLFW whether relevant keys are pressed/released this frame and react accordingly
static void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

// Whenever the window size changes (by OS or user resize) this callback function executes
static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}