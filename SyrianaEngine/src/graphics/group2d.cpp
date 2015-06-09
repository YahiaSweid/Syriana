#include "group2d.h"

namespace syriana{
	namespace graphics{

		Group2D::Group2D(maths::Matrix4 transform){
			m_TransformationMatrix = transform;
		}

		void Group2D::Add(Sprite* sprite){
			m_Sprites.push_back(sprite);
		}

		void Group2D::Render(Renderer2D* renderer) {
			renderer->PushTransformation(m_TransformationMatrix);
			for (int i = 0; i < m_Sprites.size(); i++)
				m_Sprites[i]->Render(renderer);
			renderer->PopTransformation();
		}

	}
}