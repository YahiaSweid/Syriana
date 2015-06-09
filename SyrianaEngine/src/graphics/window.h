#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <IL\il.h>
#include <IL\ilut.h>

#include "../input/keyboard.h"
#include "../input/mouse.h"

namespace syriana{
	namespace graphics{

		class Window{
		private:
			GLFWwindow* m_Window;
			const char* m_Title;
			int m_Width, m_Height;

			input::Keyboard m_Keyboard;
			input::Mouse m_Mouse;

		public:
			Window(const char* title, int width, int height);
			~Window();
			void Update();
			void ClearScreen();
			int IsClosed();

		private:
			void InitGlew();
			void InitDevIL();
			void WindowCallbacks();
			void CenterTheWindow();

			// GLFW Callbacks
			friend void window_size_callback(GLFWwindow* window, int width, int height);
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
			friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);



		};



	}
}