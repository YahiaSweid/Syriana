#pragma once

#include <vector>
#include "sprite.h"
#include "../maths/matrix4.h"

namespace syriana{
	namespace graphics{

		class Group2D : public Sprite{
		private:
			std::vector<Sprite*> m_Sprites;
			maths::Matrix4 m_TransformationMatrix;
		public:
			Group2D(maths::Matrix4 transform);
			void Add(Sprite* sprite);
			void Render(Renderer2D* renderer) override;
		};

	}
}