#include "mouse.h"

namespace syriana{
	namespace input{

		double Mouse::m_X = 0;
		double Mouse::m_Y = 0;
		bool Mouse::m_Buttons[MAX_BUTTONS];

		Mouse::Mouse(){
			for (int i = 0; i < MAX_BUTTONS; i++)
				m_Buttons[i] = false;
		}

		void Mouse::SetCoordinates(const double& x, const double& y){
			this->m_X = x;
			this->m_Y = y;
		}

		void Mouse::ButtonPressed(const int& button){
			m_Buttons[button] = true;
		}
		void Mouse::ButtonReleased(const int& button){
			m_Buttons[button] = false;
		}

		bool Mouse::IsPressed(const int& button){
			return m_Buttons[button] == true;
		}
		bool Mouse::IsReleased(const int& button){
			return m_Buttons[button] == false;
		}
	}
}