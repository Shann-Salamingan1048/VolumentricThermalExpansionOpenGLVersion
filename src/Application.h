#pragma once
#include "OpenGL.h"

class Application
{
private:
	GLFWwindow* m_window;
	OpenGL& m_context;
	void inputProcess();

public:
	explicit Application(OpenGL& context);
	void run();
	~Application() = default;
};