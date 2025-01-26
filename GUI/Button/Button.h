#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_images.h>

#include "../Base Shape Square/SquareBase.h"
class Button : public SquareBase
{
private:
	GLFWwindow* m_window;
	int m_windowWidth;
	int m_windowHeight;

private:
	Shader* m_shaderProgram; 
	VAO* m_vao1;
	VBO* m_vbo1;
	EBO* m_ebo1;

private:
	float m_vertices[32] =
	{
		// positions          // colors             // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right (Red)
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f, // bottom right (Red)
		-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // bottom left (Red)
		-0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 1.0f  // top left (Red)
	};

	uint32_t m_indices[6] =
	{
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

public:
	explicit Button(GLFWwindow* window, const float xPos, const float yPos, const uint32_t width, const uint32_t height); 
	Button();
	~Button();

private:
	float xPos, yPos;
	uint32_t width, height;

public:
	bool isHovered;
	bool isClicked;

public:
	void setTexture() override;
	void setSize(uint32_t width, uint32_t height) override;
	void setPosition(float x, float y) override;
	void setShader(const std::string& vertPath, const std::string& fragPath) override;
	void render() override;
};