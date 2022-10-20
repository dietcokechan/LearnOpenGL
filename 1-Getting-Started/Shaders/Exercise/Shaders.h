#ifndef SHADERS_CLASS_H
#define SHADERS_CLASS_H

// shader paths
const char *vertShaderPath = "C:/Users/Habiba/Code/LearnOpenGL/1-Getting-Started/Shaders/Exercise/default.vert";
const char *fragShaderPath = "C:/Users/Habiba/Code/LearnOpenGL/1-Getting-Started/Shaders/Exercise/default.frag";

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
static const unsigned int scr_width = 800;
static const unsigned int scr_height = 600;

#endif