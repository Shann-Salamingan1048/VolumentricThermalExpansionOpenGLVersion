#pragma once
#include <glad/glad.h>
#include <iostream>
// Element Buffer Object (EBO)
struct EBO
{
	GLuint ID;
	explicit EBO(GLuint* indices, GLsizeiptr size);
	EBO() = default;
	~EBO();

	void Bind();
	void Unbind();
	void Delete();
};