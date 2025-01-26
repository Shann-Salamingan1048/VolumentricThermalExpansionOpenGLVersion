#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../ObjectFiles/ObjectHeaders.h"

class SquareBase 
{
public:
    virtual void setTexture() = 0;
    virtual void setSize(uint32_t width, uint32_t height) = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void setShader(const std::string& vertPath, const std::string& fragPath) = 0;
    virtual void render() = 0;

public:
    SquareBase() = default;
    virtual ~SquareBase() = 0;

};
