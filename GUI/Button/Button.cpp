#include "Button.h"

Button::Button(GLFWwindow* window, const float xPos, const float yPos, const uint32_t width, const uint32_t height)
	: isHovered(false), isClicked(false), xPos(xPos), yPos(yPos), width(width), height(height), m_window(window), isDefaultConstructor(false),
	  m_windowWidth(0), m_windowHeight(0)
{
	std::cout << "but with parameter is initialzied\n";
	glfwGetWindowSize(m_window, &m_windowWidth, &m_windowHeight);

	shaderProgram = Shader("GUI/Button/button.vert", "GUI/Button/button.frag");

	vao1.Bind();
	vbo1 = VBO(vertices, sizeof(vertices));
	colorVbo = VBO(colors, sizeof(colors));
	ebo1 = EBO(indices, sizeof(indices));
	// size 5 thats why it is 5
	// Position attribute . Positiont set to 0
	vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 5 * sizeof(GLfloat), (void*)0);
	// Texture Coordinate attribute. set to 1
	// will start at 3rd index thats why it is 3
	vao1.LinkAttrib(vbo1, 1, 2, GL_FLOAT, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

	// colors
	vao1.LinkAttrib(colorVbo, 2, 3, GL_FLOAT, 3 * sizeof(GLfloat), (void*)0);

	// Unbind All Buffers
	vao1.Unbind();
	vbo1.Unbind();
	colorVbo.Unbind();
	ebo1.Unbind();
}
Button::Button()
	: isHovered(false), isClicked(false), xPos(0), yPos(0), width(0), height(0), m_window(nullptr), isDefaultConstructor(true),
	m_windowWidth(0), m_windowHeight(0)
{
	std::cout << "but with parameter is initialzied\n";

	shaderProgram = Shader("GUI/Button/button.vert", "GUI/Button/button.frag");

	vao1.Bind();
	vbo1 = VBO(vertices, sizeof(vertices));
	colorVbo = VBO(colors, sizeof(colors));
	ebo1 = EBO(indices, sizeof(indices));
	// size 5 thats why it is 5
	// Position attribute . Positiont set to 0
	vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 5 * sizeof(GLfloat), (void*)0);
	// Texture Coordinate attribute. set to 1
	// will start at 3rd index thats why it is 3
	vao1.LinkAttrib(vbo1, 1, 2, GL_FLOAT, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

	// colors
	vao1.LinkAttrib(colorVbo, 2, 3, GL_FLOAT, 3 * sizeof(GLfloat), (void*)0);

	// Unbind All Buffers
	vao1.Unbind();
	vbo1.Unbind();
	colorVbo.Unbind();
	ebo1.Unbind();
}

Button::~Button()
{
	if (isDefaultConstructor) {
		std::cout << "Object created with default constructor is being destroyed.\n";
	}
	else {
		std::cout << "Object created with parameterized constructor is being destroyed.\n";
	}
	std::cout << "Button is destroyed\n";
}
void Button::setTexture()
{

}
void Button::render()
{
	if (isDefaultConstructor) {
		std::cout << "default constructor is running and the value is: " << isDefaultConstructor << "\n";
	}
	else {
		std::cout << "parameterized constructor is running and the value is: " << isDefaultConstructor << "\n";
	}
	
	shaderProgram.Activate();
	vao1.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}