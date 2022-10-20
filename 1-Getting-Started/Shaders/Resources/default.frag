#version 330 core
out vec4 FragColor;
in vec3 cornerColor;

void main()
{
    FragColor = vec4(cornerColor, 1.0f);
}