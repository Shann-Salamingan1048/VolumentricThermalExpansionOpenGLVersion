#pragma once
#include "../Base Shape Square/SquareBase.h"
class Button : public SquareBase
{
public:
	explicit Button(GLFWwindow* window, const float xPos, const float yPos, const uint32_t width, const uint32_t height); 
	Button();
	~Button();

public:
	bool isHovered;
	bool isClicked;

public:
	void render() override;
	void setTexture() override;
	void setSize(float width, float height) override;
	void setPosition(float x, float y) override;
	void setShader(const std::string& vertPath, const std::string& fragPath) override;
};