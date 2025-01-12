#include "OpenGL.h"

void OpenGL::init()
{
	// init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
	// set the window hint to get forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	// set the window hint to disable resizing
}
OpenGL::OpenGL(uint32_t width, uint32_t height, const char* title)
	: m_window(nullptr)
{
	init();
	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (m_window == nullptr)
	{
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return;
	}
	// Make the context of our window the current active context
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1); // Synchronizes the Frame Rate with the Monitor's Refresh Rate:
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD\n";
		glfwTerminate();
		return;
	}
	// Set the initial viewport
	glViewport(0, 0, width, height);

	// Optional: Set callbacks, such as resizing
	glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* win, int w, int h) 
	{
		glViewport(0, 0, w, h);
	} );
}
OpenGL::~OpenGL()
{
	if (m_window)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}
	std::cout << "OpenGL destroyed\n";
}
GLFWwindow* OpenGL::getWindow() const
{
	return m_window;
}