#pragma once

#include "keys_code.h"

namespace syriana{
	namespace input{

		struct Controller{
		public:
			int MoveUp = KEY_W;
			int MoveDown = KEY_S;
			int MoveRight = KEY_D;
			int MoveLeft = KEY_A;
			int Jump = KEY_SPACE;

			int MouseRightButton = MOUSE_RIGHTBUTTON;
			int MouseLeftButton = MOUSE_LEFTBUTTON;
			int MouseMidButton = MOUSE_MIDDLEBUTTON;
		};

	}
}