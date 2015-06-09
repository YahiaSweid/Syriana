#pragma once
#include <GL\glew.h>
#include "sprite.h"
#include "transformation.h"

namespace syriana{
	namespace graphics{
		
		struct BufferData;
		class Sprite;

		class Renderer2D : public Transformation{
		private:
			GLuint m_Array;
			GLuint m_Buffer;
			GLuint m_IndexBuffer;
			int m_IndicesCount;

			BufferData* m_BufferData;
			std::vector<GLuint> m_TexIDs;
		
			// Used in push sprite method
			GLuint m_TexID;
			int m_TexIndex;
			bool m_TexFound;

		public:
			Renderer2D::Renderer2D();
			Renderer2D::~Renderer2D();

			void Renderer2D::Prepare();
			void Renderer2D::Push(Sprite* sprite);
			void Renderer2D::End();
			
			void Renderer2D::Render();
		};

	}
}