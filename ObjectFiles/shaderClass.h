#pragma once
#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cerrno>

std::string getFileContent(const std::string& fileName);
class Shader
{
public:
	GLuint ID;
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	Shader();
	~Shader();

public:
	void fragShadeOnly(const std::string& fragmentPath);
	void vertShadeOnly(const std::string& vertexPath);

public:
	// utility uniform functions
	void setBool(const std::string& name, bool value) const; // set the value of a uniform boolean
	void setInt(const std::string& name, int value) const; // set the value of a uniform int
	void setFloat(const std::string& name, float value) const; // set the value of a uniform float

public:
	void Activate();
	void Delete();

private:
	void CheckCompileErrors(GLuint shader, const std::string& type);


};