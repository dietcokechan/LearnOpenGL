#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>
#include "VBO.h"

class VAO
{
public:
    // Reference ID for Vertex Array Object
    GLuint ID;

    // Constructor with no parameters
    VAO();

    // Linking a VBO to the VAO using a certain layout
    void LinkVBO(VBO &VBO, GLuint layout);
    
    void Bind();
    void Unbind();
    void Delete();
};

#endif