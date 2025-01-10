#pragma once
#include <glad/glad.h>
// Element Buffer Object (EBO)
struct EBO
{
	GLuint ID;
	explicit EBO(GLuint* indices, GLsizeiptr size);
	~EBO();

	void Bind();
	void Unbind();
	void Delete();
};