#include "keyboard.h"

namespace syriana{
	namespace input{

		bool Keyboard::m_Keys[MAX_KEYS];

		Keyboard::Keyboard(){
			for (int i = 0; i < MAX_KEYS; i++)
				m_Keys[i] = false;
		}

		void Keyboard::KeyPressed(const int keyCode){
			m_Keys[keyCode] = true;
		}

		void Keyboard::KeyReleased(const int keyCode){
			m_Keys[keyCode] = false;
		}

		bool Keyboard::IsPressed(const int keyCode){
			return (m_Keys[keyCode] == true);
		}

		bool Keyboard::IsReleased(const int keyCode){
			return (m_Keys[keyCode] == false);
		}

	}
}