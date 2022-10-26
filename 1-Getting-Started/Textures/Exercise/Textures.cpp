/*
Exercise 1:
Make sure only the happy face looks in the other/reverse direction by changing the fragment shader
-> done in resources/default.frag by changing `texCoord` to `vec2(1.0 - texCoord.x, texCoord.y)`

Exercise 2:
Experiment with the different texture wrapping methods by specifying texture coordinates in the range 0.0f to 2.0f instead of 0.0f to 1.0f. See if you can display 4 smiley faces on a single container image clamped at its edge
-> each texture has different texture filtering settings

Exercise 3:
Experiment with the different texture wrapping methods by specifying texture coordinates in the range 0.0f to 2.0f instead of 0.0f to 1.0f. See if you can display 4 smiley faces on a single container image clamped at its edge

Exercise 4:
Use a uniform variable as the mix function's third parameter to vary the amount the two textures are visible. Use the up and down arrow keys to change how much the container or the smiley face is visible
-> processInput method now changes `uniform float mixValue` depending on which key is pressed
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Textures.h"
#include "ShaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "Includes/stb_image.h"

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
        // Positions        // Colors           // Texture
         0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 2.0f,      // Top (red)
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,      // Bottom left (green)
         0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  2.0f, 0.0f      // Bottom right (blue)
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

    unsigned int texture0, texture1;
    glGenTextures(1, &texture0);
    glBindTexture(GL_TEXTURE_2D, texture0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    float borderColor[] = {1.0f, 1.0f, 0.0f, 1.0f};
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    // Texture
    int imgWidth, imgHeight, colChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("../../../../../1-Getting-Started/Textures/Exercise/egg.png", &imgWidth, &imgHeight, &colChannels, 0);

    if(data)
    {

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    data = stbi_load("../../../../../1-Getting-Started/Textures/Exercise/wicked.png", &imgWidth, &imgHeight, &colChannels, 0);

    if (data)
    {

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);

    shaderProgram.Activate();
    glUniform1i(glGetUniformLocation(shaderProgram.ID, "tex1"), 0);
    shaderProgram.setInt("tex1", 1);

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

        // Bind Texture object
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture1);

        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();
    
        // Draw the triangle using OpenGL's primitive GL_TRIANGLES
        glDrawArrays(GL_TRIANGLES, 0, 3);

        shaderProgram.setFloat("mixValue", mixValue);

        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window);
        // Check and call GLFW events
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    glDeleteTextures(1, &texture0);
    glDeleteTextures(1, &texture1);
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

    // Press up arrow to make tex1 more visible
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        mixValue += 0.0001f;
        if(mixValue >= 1.0f)
        {
            mixValue = 1.0f;
        }
    }
    
    // Press down arrow to make tex0 more visible
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        mixValue -= 0.0001f;
        if (mixValue <= 0.0f)
        {
            mixValue = 0.0f;
        }
    }
}

// Whenever the window size changes (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}