#include "Button.h"

Button::Button(GLFWwindow* window, const float xPos, const float yPos, const uint32_t width, const uint32_t height)
    : isHovered(false), isClicked(false), xPos(xPos), yPos(yPos), width(width), height(height), m_window(window),
    m_windowWidth(0), m_windowHeight(0)
{
    std::cout << "but with parameter is initialized\n";
    if (m_window)
        glfwGetWindowSize(m_window, &m_windowWidth, &m_windowHeight);

    shaderProgram = new Shader("GUI/Button/button.vert", "GUI/Button/button.frag");
    vao1 = new VAO();
    vao1->Bind();
    vbo1 = new VBO(vertices, sizeof(vertices)); // Using the combined vertices array
    ebo1 = new EBO(indices, sizeof(indices));

    vao1->LinkAttrib(*vbo1, 0, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)0); // Position (3 floats)
    vao1->LinkAttrib(*vbo1, 1, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat))); // Color (3 floats)
    vao1->LinkAttrib(*vbo1, 2, 2, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat))); // Texture coords (2 floats)
    
    vao1->Unbind();
    vbo1->Unbind();
    ebo1->Unbind();

}

Button::Button()
	: isHovered(false), isClicked(false), xPos(0), yPos(0), width(0), height(0), m_window(nullptr),
	m_windowWidth(0), m_windowHeight(0)
{
	std::cout << "but with no parameter is initialzied\n";
}

Button::~Button()
{

	std::cout << "Button is destroyed\n";
}
void Button::setTexture()
{

}
void Button::render()
{
	shaderProgram->Activate();
	vao1->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);;

}