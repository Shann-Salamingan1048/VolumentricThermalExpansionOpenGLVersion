#pragma once
// Vertex Array Object (VAO)

#include <glad/glad.h>
#include "VBO.h"

struct VAO
{
	GLuint ID;
	VAO();
	~VAO();

	void LinkAttrib(VBO& VBO, GLuint layout);
	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();

};