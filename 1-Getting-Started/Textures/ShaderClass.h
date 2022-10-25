#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Shader
{
public:
    // Reference ID of the Shader Program
    GLuint ID;
    
    // Constructor that build the Shader Program from 2 different shaders
    Shader(const char *vertexFile, const char *fragmentFile);

    // Utility uniform functions (query a uniform location and set its value)
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

    // Activates the Shader Program
    void Activate();
    // Deletes the Shader Program
    void Delete();
};

#endif