#include "Application.h"

Application::Application(OpenGL& context)
	: m_context(context), m_window(nullptr)
{
    m_window = m_context.getWindow();
    m_but1 = Button(m_window, 0, 0, 300, 300);
}
void Application::run()
{
    while (!glfwWindowShouldClose(m_window)) 
    {
        inputProcess();

        // Rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Add rendering code here...
        m_but1.render();

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
Application::~Application()
{
    std::cout << "Application destroyed\n";
}