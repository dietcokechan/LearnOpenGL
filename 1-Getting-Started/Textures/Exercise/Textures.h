#ifndef TEXTURES_CLASS_H
#define TEXTURES_CLASS_H

// shader paths
const char *vertShaderPath = "../../../../../1-Getting-Started/Textures/Exercise/Resources/default.vert";
const char *fragShaderPath = "../../../../../1-Getting-Started/Textures/Exercise/Resources/default.frag";

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
static const unsigned int scr_width = 800;
static const unsigned int scr_height = 600;

float mixValue = 0.2f;

#endif