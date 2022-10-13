#include "VAO.h"

VAO::VAO()
{
    // Generate the VAO and VBO with 1 object each
    glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO &VBO, GLuint layout)
{
    VBO.Bind();

    // Configure the Vertex Attribute so that OpenGL knows how to read the VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    // Enable the Vertex Attribute so that OpenGL knows to use it
    glEnableVertexAttribArray(0);

    VBO.Unbind();
}

void VAO::Bind()
{
    // Make the VAO the current Vertex Array Object by binding it
    glBindVertexArray(ID);
}

void VAO::Unbind()
{
    glBindVertexArray(0);
}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &ID);
}