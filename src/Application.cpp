#include "Application.h"

Application::Application(OpenGL& context)
	: m_context(context), m_window(nullptr)
{
	m_window = m_context.getWindow();
}
void Application::run()
{
    while (!glfwWindowShouldClose(m_window)) 
    {
        inputProcess();

        // Rendering
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Add rendering code here...

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

void Application::inputProcess()
{
	if (glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS) 
	{
		glfwSetWindowShouldClose(m_window, true);
	}
}