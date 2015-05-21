#include "sprite.h"

namespace syriana{
	using namespace maths;
	namespace graphics{

		Sprite::Sprite(const Vector3& position, const Vector2& size, const Vector4& color){
			this->position = position;
			this->size = size;
			this->color = color;
		}


	}
}