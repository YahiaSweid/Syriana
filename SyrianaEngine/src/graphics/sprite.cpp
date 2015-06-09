#include "sprite.h"

namespace syriana{
	using namespace maths;
	namespace graphics{

		Sprite::Sprite(const Vector3& position, const Vector2& size, const Vector4& color){
			this->position = position;
			this->size = size;
			this->color = color;
			this->SetUVs();
			m_Texture = nullptr;
		}

		Sprite::Sprite(const Vector3& position, const Vector2& size, Texture* texture){
			this->position = position;
			this->size = size;
			this->color = Vector4(1,1,1,1);
			this->SetUVs();
			m_Texture = texture;
		}

		Sprite::Sprite(const Vector3& position, const Vector2& size, Texture* texture, const Vector4& color){
			this->position = position;
			this->size = size;
			this->color = color;
			this->SetUVs();
			m_Texture = texture;
		}

		void Sprite::Render(Renderer2D* renderer){
			renderer->Push(this);
		}

		GLuint Sprite::GetTexID(){
			if (m_Texture != nullptr)
				return m_Texture->GetTexID();
			return 0;
		}

		void Sprite::SetUVs(){
			uvs.push_back(Vector2(0, 0));
			uvs.push_back(Vector2(1, 0));
			uvs.push_back(Vector2(1, 1));
			uvs.push_back(Vector2(0, 1));
		}


	}
}