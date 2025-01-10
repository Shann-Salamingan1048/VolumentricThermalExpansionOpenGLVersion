#pragma once
// Vertex Buffer Object (VBO)
#include <glad/glad.h>

struct VBO
{
	GLuint ID;
	VBO(GLfloat* vertices, GLsizeiptr size);
	~VBO();

	void Bind();
	void Unbind();
	void Delete();


};
