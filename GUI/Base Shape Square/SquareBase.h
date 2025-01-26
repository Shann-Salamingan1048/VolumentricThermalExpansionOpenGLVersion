#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../ObjectFiles/ObjectHeaders.h"

class SquareBase 
{
protected:
    virtual void setTexture() = 0;
    virtual void setSize(float width, float height) = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void setShader(const std::string& vertPath, const std::string& fragPath) = 0;

protected:
    Shader* shaderProgram;
    VAO* vao1;
    VBO* vbo1;
    EBO* ebo1;

protected:
    GLFWwindow* b_window;
    int b_windowWidth;
    int b_windowHeight;

protected:
    float xPos, yPos;
    uint32_t width, height;

protected:
    float base_vertices[32] =
    {
        // positions          // colors             // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right (Red)
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f, // bottom right (Red)
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // bottom left (Red)
        -0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 1.0f  // top left (Red)
    };

    uint32_t base_indices[6] =
    {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

public:
    SquareBase();
    SquareBase(GLFWwindow* window, float x, float y, uint32_t width, uint32_t height);
    virtual ~SquareBase();

public:
    virtual void render();
};
