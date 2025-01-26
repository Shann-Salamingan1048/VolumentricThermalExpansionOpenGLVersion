#include "Button.h"

Button::Button(GLFWwindow* window, const float xPos, const float yPos, const uint32_t width, const uint32_t height)
    : isHovered(false), isClicked(false), xPos(xPos), yPos(yPos), width(width), height(height), m_window(window),
    m_windowWidth(0), m_windowHeight(0)
{
    std::cout << "but with parameter is initialized\n";
    if (m_window)
        glfwGetWindowSize(m_window, &m_windowWidth, &m_windowHeight);

    m_shaderProgram = new Shader("GUI/Button/button.vert", "GUI/Button/button.frag");
    m_vao1 = new VAO();
    m_vao1->Bind();
    m_vbo1 = new VBO(m_vertices, sizeof(m_vertices)); // Using the combined vertices array
    m_ebo1 = new EBO(m_indices, sizeof(m_indices));

    m_vao1->LinkAttrib(*m_vbo1, 0, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)0); // Position (3 floats)
    m_vao1->LinkAttrib(*m_vbo1, 1, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat))); // Color (3 floats)
    m_vao1->LinkAttrib(*m_vbo1, 2, 2, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat))); // Texture coords (2 floats)

    m_vao1->Unbind();
    m_vbo1->Unbind();
    m_ebo1->Unbind();

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
void Button::render()
{
    m_shaderProgram->Activate();
    m_vao1->Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);;

}
void Button::setTexture()
{
    // soon to be coded
}
void Button::setShader(const std::string& vertPath, const std::string& fragPath)
{
    m_shaderProgram = new Shader(vertPath, fragPath);
}
void Button::setSize(uint32_t width, uint32_t height)
{
    m_windowWidth = width;
    m_windowHeight = height;
}
void Button::setPosition(float x, float y)
{
    xPos = x;
    yPos = y;
}