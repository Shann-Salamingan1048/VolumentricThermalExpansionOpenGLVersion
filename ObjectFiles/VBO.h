#pragma once
// Vertex Buffer Object (VBO)
#include <glad/glad.h>
#include <iostream>
struct VBO
{
	GLuint ID;
	VBO(GLfloat* vertices, GLsizeiptr size);
	VBO() = default;
	~VBO();

	void Bind();
	void Unbind();
	void Delete();


};
