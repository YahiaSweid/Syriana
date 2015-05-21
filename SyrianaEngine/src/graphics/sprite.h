#pragma once

#include "../maths/vector2.h"
#include "../maths/vector3.h"
#include "../maths/vector4.h"

namespace syriana{
	using namespace maths;
	namespace graphics{

		struct BufferData{
			Vector3 position;
			Vector4 color;
		};

		class Sprite{
		public:
			Vector3 position;
			Vector2 size;
			Vector4 color;
		public:
			Sprite(const Vector3& position, const Vector2& size, const Vector4& color);
		};

	}
}