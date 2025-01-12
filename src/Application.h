#pragma once
#include "OpenGL.h"
#include "../GUI/Button/Button.h"
class Application
{
private:
	GLFWwindow* m_window;
	OpenGL& m_context;
	void inputProcess();

private:
	Button m_but1;

public:
	explicit Application(OpenGL& context);
	void run();
	~Application();
};