#version 330 core

out vec4 FragColor;

in vec3 cornerColor;
in vec2 texCoord;

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform float mixValue;

void main()
{
    FragColor = mix(texture(tex0, texCoord), texture(tex1, vec2(1.0 - texCoord.x, texCoord.y)), mixValue);
}