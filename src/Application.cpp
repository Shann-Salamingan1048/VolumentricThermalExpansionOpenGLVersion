#include "Application.h"

Application::Application(OpenGL& context)
    : m_context(context), m_window(context.getWindow()), m_but1(m_window, 0, 0, 300, 300)
{
    std::cout << "Application initialized\n";

}

void Application::run()
{
    while (!glfwWindowShouldClose(m_window)) 
    {
        inputProcess();


        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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