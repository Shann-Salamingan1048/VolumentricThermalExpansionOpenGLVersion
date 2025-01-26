#include "Button.h"

Button::Button(GLFWwindow* window, float x, float y, uint32_t w, uint32_t h)
    : SquareBase(window,x,y,w,h),
    isHovered(false), isClicked(false) 
{
    std::cout << "Button initialized with parameters\n";

}

Button::Button() : Button(nullptr, 0, 0, 0, 0) 
{
    std::cout << "Default Button initialized\n";
}

Button::~Button() 
{
    std::cout << "Button destroyed\n";
}
void Button::render()
{
    //std::cout << "waya ra\n";
    SquareBase::render();
}
void Button::setTexture() 
{
    // Implement texture loading logic
}
void Button::setShader(const std::string& vertPath, const std::string& fragPath)
{
    shaderProgram = new Shader(vertPath, fragPath);
}
void Button::setSize(float w, float h) 
{
    width = w;
    height = h;
}

void Button::setPosition(float x, float y) 
{
    xPos = x;
    yPos = y;
}
