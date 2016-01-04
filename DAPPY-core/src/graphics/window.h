#pragma once
#include<GL\glew.h>
#include<glfw\glfw3.h>
#include<iostream>



namespace dappy { namespace graphics {

#define MAX_KEYS	1024
#define MAX_BUTTONS 32

	class Window {

	private:
		
		const char *m_Title;
		int m_Height, m_Width;

		GLFWwindow * m_Window;
		bool Init();
		bool m_Closed;


		friend static void key_callback(GLFWwindow* window , int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_callback(GLFWwindow* window, double x, double y);

	
	
	public:
		
		static bool m_Keys[MAX_KEYS];
		static bool m_MouseButton[MAX_BUTTONS];
		static double mx, my;

		Window(const char * , int, int);
		~Window();
		
		void clear() const;
		void update() const;
		bool Closed() const;
		static bool isKeyPressed(unsigned int);
		static bool isMousePressed(unsigned int);
		static void getMouseposs(double &x, double &y);
	};


}	}