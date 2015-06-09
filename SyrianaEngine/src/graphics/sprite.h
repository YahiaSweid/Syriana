#pragma once

#include <vector>
#include "renderer2d.h"
#include "texture.h"
#include "../maths/vector2.h"
#include "../maths/vector3.h"
#include "../maths/vector4.h"

namespace syriana{
	using namespace maths;
	namespace graphics{

		class Renderer2D;

		struct BufferData{
			Vector3 position;
			Vector2 uvs;
			float texid;
			Vector4 color;
		};

		class Sprite{
		public:
			Vector3 position;
			Vector2 size;
			Vector4 color;
			std::vector<Vector2> uvs;

		protected:
			inline Sprite(){ SetUVs(); };
		
		public:
			Sprite(const Vector3& position, const Vector2& size, const Vector4& color);
			Sprite(const Vector3& position, const Vector2& size, Texture* texture);
			Sprite(const Vector3& position, const Vector2& size, Texture* texture, const Vector4& color);

			virtual void Render(Renderer2D* renderer);
			GLuint GetTexID();
		private:
			void SetUVs();
		private:
			Texture* m_Texture;
		};

	}
}