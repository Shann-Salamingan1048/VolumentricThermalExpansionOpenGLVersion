#include "VAO.h"

VAO::VAO() 
	:ID(0)
{
	glGenVertexArrays(1, &ID);
}
VAO::~VAO()
{
	std::cout << "VAO destroyed\n";
	Delete();
}
void VAO::LinkAttrib(VBO& VBO, GLuint layout)
{
	VBO.Bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE,0, (GLvoid*)0);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}
void VAO::Bind()
{
	glBindVertexArray(ID);
}
void VAO::Unbind()
{
	glBindVertexArray(0);
}
void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}
