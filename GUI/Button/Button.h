#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_images.h>

#include "../../ObjectFiles/ObjectHeaders.h"
class Button
{
private:
	GLFWwindow* m_window;
	int m_windowWidth;
	int m_windowHeight;

private:
	Shader shaderProgram;
	VAO vao1;
	VBO vbo1;
	VBO colorVbo;
	EBO ebo1;

// temporary
public:

	bool isDefaultConstructor;
private:
	float colors[12] = 
	{
// Color (R, G, B)
		1.0f, 0.0f, 0.0f,  // Top-left corner (Red)
		1.0f, 0.0f, 0.0f,  // Top-left corner (Red)
		1.0f, 0.0f, 0.0f,  // Top-left corner (Red)
		1.0f, 0.0f, 0.0f  // Top-left corner (Red)
	};

	float vertices[20] = 
	{
		// positions          // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
	};
	uint32_t indices[6] =
	{
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

public:
	explicit Button(GLFWwindow* window, const float xPos, const float yPos, const uint32_t width, const uint32_t height); 
	Button();
	~Button();

public:
	float xPos, yPos;
	uint32_t width, height;

public:
	bool isHovered;
	bool isClicked;

public:
	void setTexture();
	void render();
};