#include "SquareBase.h"

SquareBase::SquareBase(GLFWwindow* window, float x, float y, uint32_t width, uint32_t height) 
	: b_window(window), b_windowWidth(0), b_windowHeight(0),
	xPos(x), yPos(y), width(width), height(height) 
{
    std::cout << "SquareBase with parameters initialized\n";
    if (b_window)
        glfwGetWindowSize(b_window, &b_windowWidth, &b_windowHeight);

    shaderProgram = new Shader("GUI/Button/button.vert", "GUI/Button/button.frag");
    vao1 = new VAO();
    vbo1 = new VBO(base_vertices, sizeof(base_vertices));
    ebo1 = new EBO(base_indices, sizeof(base_indices));

    vao1->Bind();
    vao1->LinkAttrib(*vbo1, 0, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)0);
    vao1->LinkAttrib(*vbo1, 1, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    vao1->LinkAttrib(*vbo1, 2, 2, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));



    vao1->Unbind();
    vbo1->Unbind();
    ebo1->Unbind();

}
SquareBase::SquareBase() 
    : xPos(0.0f), yPos(0.0f), width(0), height(0), b_window(nullptr),
    b_windowWidth(0), b_windowHeight(0) 
{
    std::cout << "SquareBase initialized\n";
}
void SquareBase::render()
{
    if (!shaderProgram || !vao1) 
    {
        std::cerr << "Shader or VAO not initialized!" << std::endl;
        return;
    }
    //std::cout << "Rendering\n";
    shaderProgram->Activate();
    vao1->Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
SquareBase::~SquareBase()
{
    std::cout << "SquareBase destroyed\n";
    delete shaderProgram;
    delete vao1;
    delete vbo1;
    delete ebo1;
    
}