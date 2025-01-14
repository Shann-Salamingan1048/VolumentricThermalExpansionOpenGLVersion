#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_images.h>

#include "../../ObjectFiles/shaderClass.h"
#include "../../ObjectFiles/VAO.h"
#include "../../ObjectFiles/VBO.h"
#include "../../ObjectFiles/EBO.h"
class Button
{
private:
	GLFWwindow* m_window;
	int m_windowWidth;
	int m_windowHeight;

private:
	Shader* shaderProgram;
	VAO* vao1;
	VBO* vbo1;
	EBO* ebo1;

private:
	float vertices[32] =
	{
		// positions          // colors             // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right (Red)
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f, // bottom right (Red)
		-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // bottom left (Red)
		-0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 1.0f  // top left (Red)
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