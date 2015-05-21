#pragma once

#include "keys_code.h"

#define MAX_KEYS 512

namespace syriana{
	namespace input{
		class Keyboard{
		private:
			static bool m_Keys[MAX_KEYS];
		public:
			Keyboard();
			void KeyPressed(const int keyCode);
			void KeyReleased(const int key);
			bool IsPressed(const int key);
			bool IsReleased(const int key);
		};
	}
}