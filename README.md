# LearnOpenGL

This repo is for documenting my progress with the ![LearnOpenGL](learnopengl.com) chapters

## Getting Started

### ![Triangle](./1-Getting-Started/Hello-Triangle/)

In the first few chapters I learned how to set up GLFW and GLAD, creating a window, and drawing a triangle.

As well as learning how to set up CMake in the process which allowed me to have multiple .exe applications within different folders so I can make seperate applications for the chapters and exercises to showcase and document each and every step of my progress.

### First Triangle

So first thing I did was specifing my triangle's vertices and defining them in a float array, then I start creating memory on the GPU where I want to store my data, in this case my triangle vertices, and configure how I want OpenGL to interpret this data and how to send it to the GPU, then I can have the vertex shader process the vertices I tell it to process. I create a VBO (Vertex Buffer Object) and a VAO (Vertex Array Object), bind and assign data to a buffer for OpenGL to use, setting a pointer to where it should start looking at my vertices. And lastly, I create a Shader Program and attach the variables that contain my vertex shader and fragment shader to it, activating the program and bind the VBO and VAO to draw my triangle, then deleting all these resources once we're done before closing the glfw window.

![Triangle](./Progress/first_triangle.png)

### ![Triangle Exercises](./1-Getting-Started/Hello-Triangle/Exercises/)

#### **First Exercise**

Drawing 2 triangles next to each other.

![two_triangles](./Progress/two_triangles.png)

#### **Second Exercise**

Drawing 2 triangles with different Vertex Array Objects and Vertex Buffer Objects.

#### **Third Exercise**

Creating 2 shader programs where each program uses different fragment shaders that output different colors.

![diff_triangles](./Progress/different_triangles.png)

### ![Shaders](./1-Getting-Started/Shaders/)

In this chapter I learned how to understand, write and work with vertex shaders and fragment shaders, as well as organizing my source files, header files and shader files.

![tricolored](./Progress/tricolored_triangle.png)

### ![Shaders Exercises](./1-Getting-Started/Shaders/Exercise/)

#### **First Exercise**

Adjusting the vertex shader so that the triangle is upside down by simply putting a negative sign in front of the y value `aPos.y` in the vertex shader file.

![upsidedown](./Progress/upsidedown.png)

#### **Second Exercise**

Creating a horizontal offset via a `uniform float` within the ShaderClass source file using the `setFloat()` method, and then moving the triangle to the right side of the screen in the vertex shader using this offset value by adding the offset value to the x value `aPos.x` in the vertex shader file.

![rightside](./Progress/rightside.png)

#### **Third Exercise**

Outputing the vertex position to the fragment shader using the `out` keyword and setting the fragment color to this vertex position, noticing in the process that the bottom left corner of the triangle was black due to the vertex position having negative values and the rgb values have the range of 0-1 so the negative values always clamped to `0.0f` within the rgb context.

![blackcorner](./Progress/blackcorner.png)
