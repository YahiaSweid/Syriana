#pragma once
#include <GL\glew.h>
#include "sprite.h"

namespace syriana{
	namespace graphics{
		
		class Renderer2D{
		private:
			GLuint m_Array;
			GLuint m_Buffer;
			GLuint m_IndexBuffer;
			int m_IndicesCount;

			BufferData* m_BufferData;

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