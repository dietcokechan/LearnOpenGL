#ifndef SHADERS_CLASS_H
#define SHADERS_CLASS_H

// shader sources
const char *vertexShaderSource = R"(
                                        #version 330 core
                                        layout (location = 0) in vec3 aPos;
                                        void main()
                                        {
                                            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
                                        }
                                    )";

const char *fragmentShaderSource = R"(
                                        #version 330 core
                                        out vec4 FragColor;
                                        void main()
                                        {
                                            FragColor = vec4(0.6f, 0.4f, 0.8f, 1.0f);
                                        }
                                    )";

#endif