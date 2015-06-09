#include <IL/il.h>
#include <IL/ilut.h>
#include "texture.h"

namespace syriana{
	namespace graphics{

		Texture::Texture(char* filename){
			ILuint img = 0;
			ilGenImages(1, &img);
			ilBindImage(img);

			if (!ilLoadImage(filename))
				std::cout << "Could not open image: " + ilGetError() << std::endl;

			iluFlipImage();

			m_Width = ilGetInteger(IL_IMAGE_WIDTH);
			m_Height = ilGetInteger(IL_IMAGE_HEIGHT);

			m_TexID = ilutGLBindTexImage();
			if (m_TexID == 0)
				std::cout << "Could not bind image" << std::endl;

			std::cout << glGetError() << std::endl;
			
			ilDeleteImages(1, &img);
		}

		void Texture::Bind(){
			glBindTexture(GL_TEXTURE_2D, m_TexID);
		}

		void Texture::Unbind(){
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		GLuint Texture::GetTexID(){ return m_TexID; }
		int Texture::GetWidth(){ return m_Width; }
		int Texture::GetHeight(){ return m_Height; }

	}
}