#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OpenGL
{
private:
	GLFWwindow* m_window;
	void init();
public:

	explicit OpenGL(uint32_t width, uint32_t height, const char* titel);
	~OpenGL();
	GLFWwindow* getWindow() const;
};