#include "window.h"
#include <iostream>

namespace syriana{
	namespace graphics{

		Window::Window(const char* title, int width, int height)
			: m_Title(title), m_Width(width), m_Height(height){

			if (!glfwInit())
				return;

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
				glfwTerminate();

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSwapInterval(0);

			WindowCallbacks();
			CenterTheWindow();

			InitGlew();
			InitDevIL();
		}

		Window::~Window(){
			glfwTerminate();
		}

		void Window::Update(){
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}

		int Window::IsClosed(){
			return glfwWindowShouldClose(m_Window);
		}

		void Window::ClearScreen(){
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.4, 0.6, 0.9, 1.0);
		}

		void Window::CenterTheWindow(){
			GLFWmonitor* monitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(monitor);
			glfwSetWindowPos(m_Window, (mode->width - m_Width) / 2, (mode->height - m_Height) / 2);
		}

		void Window::InitGlew(){
			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK)
				std::cout << "Could not initialize GLEW" << std::endl;
			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
			std::cout << "Shading Language " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
			std::cout << "Renderer " << glGetString(GL_RENDERER) << std::endl;
		}

		void Window::InitDevIL(){
			ilInit();
			iluInit();
			ilutInit();
			ilutRenderer(ILUT_OPENGL);
		}

		void Window::WindowCallbacks(){
			glfwSetWindowSizeCallback(m_Window, window_size_callback);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
		}

		// GLFW Callbacks
		void window_size_callback(GLFWwindow* window, int width, int height){
			Window* currentWindow = (Window*)glfwGetWindowUserPointer(window);
			currentWindow->m_Width = width; currentWindow->m_Height = height;
			glViewport(0, 0, width, height);
		}
		
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
			Window* currentWindow = (Window*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS)
				currentWindow->m_Keyboard.KeyPressed(key);
			if (action == GLFW_RELEASE)
				currentWindow->m_Keyboard.KeyReleased(key);
		}
		
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
			Window* currentWindow = (Window*)glfwGetWindowUserPointer(window);
			currentWindow->m_Mouse.SetCoordinates(xpos, ypos);
		}
		
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
			Window* currentWindow = (Window*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS)
				currentWindow->m_Mouse.ButtonPressed(button);
			if (action == GLFW_RELEASE)
				currentWindow->m_Mouse.ButtonReleased(button);
		}



	}
}