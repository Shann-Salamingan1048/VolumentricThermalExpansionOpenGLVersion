#include "Button.h"

Button::Button(GLFWwindow* window, float xPos, float yPos, uint32_t width, uint32_t height)
	: isHovered(false), isClicked(false), xPos(xPos), yPos(yPos), width(width), height(height), m_window(window)
{
	
}

Button::~Button()
{

}

void Button::render()
{

}