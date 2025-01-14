#include "shaderClass.h"
Shader::Shader() : ID(0) {}
Shader::~Shader()
{
	std::cout << "shader has been destroyed\n";
	Delete();
}

std::string getFileContent(const std::string& fileName)
{
	std::ifstream file(fileName, std::ios::binary);
	if (file)
	{
		std::string content;
		file.seekg(0, std::ios::end);
		content.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&content[0], content.size());
		file.close();
		return content;
	}
	throw(errno);
}
void Shader::vertShadeOnly(const std::string& vertexPath)
{
	std::string vertexCode = getFileContent(vertexPath);
	const char* vShaderCode = vertexCode.c_str();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
	glCompileShader(vertexShader);
	CheckCompileErrors(vertexShader, "VERTEX");
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glLinkProgram(ID);
	CheckCompileErrors(ID, "PROGRAM");
	glDeleteShader(vertexShader);
}
void Shader::fragShadeOnly(const std::string& fragmentPath)
{
	std::string fragmentCode = getFileContent(fragmentPath);
	const char* fShaderCode = fragmentCode.c_str();
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
	glCompileShader(fragmentShader);
	CheckCompileErrors(fragmentShader, "FRAGMENT");
	ID = glCreateProgram();
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	CheckCompileErrors(ID, "PROGRAM");
	glDeleteShader(fragmentShader);
}
Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
	: ID(0)
{
	// read the vertex and fragment shader files
	std::string vertexCode = getFileContent(vertexPath);
	std::string fragmentCode = getFileContent(fragmentPath);
	// convert the strings to char arrays
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();
	// Create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
	glCompileShader(vertexShader);
	CheckCompileErrors(vertexShader, "VERTEX");

	// Create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
	glCompileShader(fragmentShader);
	CheckCompileErrors(fragmentShader, "FRAGMENT");

	// Create Shader Program Object and get its reference
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	CheckCompileErrors(ID, "PROGRAM");
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::Activate()
{
	glUseProgram(ID);
	GLint success;
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[1024];
		glGetProgramInfoLog(ID, 1024, nullptr, infoLog);
		std::cerr << "ERROR::SHADER_PROGRAM_LINKING_ERROR: " << infoLog << std::endl;
	}
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}
void Shader::CheckCompileErrors(GLuint shader, const std::string& type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
			std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- -----------------------------------------------------\n";
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
			std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- -----------------------------------------------------\n";
		}
	}
}