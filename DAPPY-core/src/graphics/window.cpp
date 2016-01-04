#include "window.h"

#include<glfw\glfw3.h>

using namespace dappy;
using namespace graphics;

bool Window::m_Keys[MAX_KEYS];
bool Window::m_MouseButton[MAX_BUTTONS];
double Window::mx, Window::my;

void windowResize(GLFWwindow * window, int h, int w) {
	glViewport(0,0,w,h);
}

Window::Window(const char *title, int w , int h )
{
	m_Height = h;
	m_Title = title;
	m_Width = w;

	if (!Init())
		glfwTerminate();

	for (int i = 0; i < MAX_KEYS; i++)
		m_Keys[i] = false;

	for (int i = 0; i < MAX_BUTTONS; i++)
		m_MouseButton[i] = false;

}

Window::~Window()
{
	glfwTerminate();
}

bool Window::Init()
{

	if (!glfwInit())
	{

		std::cout << "Error On Initialization of GLFW" << std::endl;
		return false;
	}
	

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	
	if (!m_Window) {
		glfwTerminate();
		std::cout << "Failed to Create Window" << std::endl;
		return false;
	}

	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	//glfwSetWindowSizeCallback(m_Window, windowResize);
	glfwSetKeyCallback(m_Window, key_callback);
	glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
	glfwSetCursorPosCallback(m_Window, cursor_callback);
	glfwSwapInterval(0.0);				// to disable VSync

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (glewInit()!= GLEW_OK) {
		std::cout << "Cant Init GLEW !!" << std::endl;
		return false;
	}

	std::cout << glGetString(GL_VERSION)<<std::endl; 
		   
	return true;
}

void Window::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void Window::update() const
{
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		std::cout <<"Open_GL error : " << error << std::endl;
		system("pause");
	}

	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

bool Window::Closed() const
{
	return glfwWindowShouldClose(m_Window)==1;
}

bool Window::isKeyPressed(unsigned int x)
{
	
	//TODO: LOd this !!
	if (x >= MAX_KEYS)
		return false;
	
	return m_Keys[x];
}

bool dappy::graphics::Window::isMousePressed(unsigned int x)
{  
	if(x>=MAX_BUTTONS)
	return false;

	return m_MouseButton[x];
}

void dappy::graphics::Window::getMouseposs(double & x, double & y)
{
	x = mx;
	y = my;
}



void dappy::graphics::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_Keys[key] = action != GLFW_RELEASE;
}

void dappy::graphics::mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_MouseButton[button] = action != GLFW_RELEASE;
}

void dappy::graphics::cursor_callback(GLFWwindow * window, double x, double y)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->mx = x;
	win->my = y;
}

