#version 330 core
out vec4 FragColor;
// in vec3 cornerColor;
in vec3 myPos;

void main()
{
    FragColor = vec4(myPos, 1.0f);
}