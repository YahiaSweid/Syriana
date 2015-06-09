#pragma once

#include <iostream>
#include <string>

namespace syriana{
	namespace graphics{

		class Texture {
		private:
			GLuint m_TexID;
			GLint m_Width, m_Height;
		public:
			Texture(char* filename);
			void Bind();
			void Unbind();
			
			GLuint GetTexID();
			int GetWidth();
			int GetHeight();


		};

	}
}