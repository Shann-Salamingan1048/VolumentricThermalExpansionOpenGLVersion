#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_images.h>
#include "../../ObjectFiles/ObjectHeaders.h"
class Button
{
private:
	GLFWwindow* m_window;

public:
	explicit Button(GLFWwindow* window, float xPos, float yPos, uint32_t width, uint32_t height); 
	~Button();

public:
	float xPos, yPos;
	uint32_t width, height;

	bool isHovered;
	bool isClicked;

public:
	void render();
};