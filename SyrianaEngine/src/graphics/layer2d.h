#pragma once

#include <vector>
#include "sprite.h"
#include "shader.h"
#include "../maths/matrix4.h"

namespace syriana{
	namespace graphics{

		class Layer2D{
		private:
			Shader* m_Shader;
			std::vector<Sprite*> m_Sprites;
			maths::Matrix4 m_ProjectionMatrix;
		public:
			Renderer2D* m_Renderer;
		public:
			Layer2D(Renderer2D* renderer, Shader* shader, maths::Matrix4 projectionMatrix);
			~Layer2D();
			void Add(Sprite* sprite);
			void Render();
		};

	}
}