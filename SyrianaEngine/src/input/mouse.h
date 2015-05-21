#pragma once

#include "../maths/vector2.h"
#include "keys_code.h"

#define MAX_BUTTONS 12

namespace syriana{
	namespace input{

		class Mouse{
		public:
			static double m_X, m_Y;
			static bool m_Buttons[MAX_BUTTONS];
		public:
			Mouse();
			void SetCoordinates(const double& x, const double& y);
			void ButtonPressed(const int& button);
			void ButtonReleased(const int& button);
			bool IsPressed(const int& button);
			bool IsReleased(const int& button);
		};

	}
}