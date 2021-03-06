#include "renderer2d.h"
#include "definitions.h"

namespace syriana{
	namespace graphics{

		Renderer2D::Renderer2D()
			: m_IndicesCount(0) {
			glGenVertexArrays(1, &m_Array);
			glGenBuffers(1, &m_Buffer);
			glGenBuffers(1, &m_IndexBuffer);
			// VAO
			glBindVertexArray(m_Array);
			{
				// VBO
				glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
				{
					glBufferData(GL_ARRAY_BUFFER, DEF_BUFFER_SIZE, NULL, GL_STATIC_DRAW);


					glEnableVertexAttribArray(DEF_VERTEX_POSITION_INDEX);
					glVertexAttribPointer(DEF_VERTEX_POSITION_INDEX, 3, GL_FLOAT, GL_FALSE, DEF_VERTEX_SIZE, 0);

					glEnableVertexAttribArray(DEF_VERTEX_UVS_INDEX);
					glVertexAttribPointer(DEF_VERTEX_UVS_INDEX, 2, GL_FLOAT, GL_FALSE, DEF_VERTEX_SIZE, (void*)offsetof(BufferData, uvs));

					glEnableVertexAttribArray(DEF_VERTEX_TEXID_INDEX);
					glVertexAttribPointer(DEF_VERTEX_TEXID_INDEX, 1, GL_FLOAT, GL_FALSE, DEF_VERTEX_SIZE, (void*)offsetof(BufferData, texid));

					glEnableVertexAttribArray(DEF_VERTEX_COLOR_INDEX);
					glVertexAttribPointer(DEF_VERTEX_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, DEF_VERTEX_SIZE, (void*)offsetof(BufferData, color));
				}
				glBindBuffer(GL_ARRAY_BUFFER, 0);

				// IBO
				GLuint indices[DEF_INDICES_SIZE];

				unsigned int offset = 0;
				for (int i = 0; i < DEF_INDICES_SIZE; i += 6){
					indices[i] = offset + 0;
					indices[i + 1] = offset + 1;
					indices[i + 2] = offset + 2;
					indices[i + 3] = offset + 2;
					indices[i + 4] = offset + 3;
					indices[i + 5] = offset + 0;
					offset += 4;
				}

				
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
				{
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, DEF_INDICES_SIZE, indices, GL_STATIC_DRAW);
				}
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			}
			glBindVertexArray(0);

		}

		Renderer2D::~Renderer2D(){
			glDeleteBuffers(1, &m_Buffer);
			glDeleteBuffers(1, &m_IndexBuffer);
		}


		void Renderer2D::Prepare(){
			glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
			m_BufferData = (BufferData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}

		void Renderer2D::Push(Sprite* sprite){
			m_TexID = sprite->GetTexID();
			m_TexIndex = 0;
			m_TexFound = false;
			if (m_TexID > 0){
				for (int i = 0; i < m_TexIDs.size(); i++){
					if (m_TexIDs[i] == m_TexID){
						m_TexIndex = i + 1;
						m_TexFound = true;
						break;
					}
				}

				if (!m_TexFound){
					if (m_TexIDs.size() >= 32){
						this->End();
						this->Render();
						this->Prepare();
					}

					m_TexIDs.push_back(m_TexID);
					m_TexIndex = m_TexIDs.size();
				}
			}

			m_BufferData->position = *m_TransformationBack * sprite->position;
			m_BufferData->uvs = sprite->uvs[0];
			m_BufferData->texid = m_TexIndex;
			m_BufferData->color = sprite->color;
			m_BufferData++;

			m_BufferData->position = *m_TransformationBack * Vector3(sprite->position.x + sprite->size.x, sprite->position.y, sprite->position.z);
			m_BufferData->uvs = sprite->uvs[1];
			m_BufferData->texid = m_TexIndex;
			m_BufferData->color = sprite->color;
			m_BufferData++;

			m_BufferData->position = *m_TransformationBack * Vector3(sprite->position.x + sprite->size.x, sprite->position.y + sprite->size.y, sprite->position.z);;
			m_BufferData->uvs = sprite->uvs[2];
			m_BufferData->texid = m_TexIndex;
			m_BufferData->color = sprite->color;
			m_BufferData++;

			m_BufferData->position = *m_TransformationBack * Vector3(sprite->position.x, sprite->position.y + sprite->size.y, sprite->position.z);;
			m_BufferData->uvs = sprite->uvs[3];
			m_BufferData->texid = m_TexIndex;
			m_BufferData->color = sprite->color;
			m_BufferData++;

			m_IndicesCount += 6;
		}

		void Renderer2D::End(){
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void Renderer2D::Render(){
			for (int i = 0; i < m_TexIDs.size(); i++){
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, m_TexIDs[i]);
			}
			glBindVertexArray(m_Array);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
			glDrawElements(GL_TRIANGLES, m_IndicesCount, GL_UNSIGNED_INT, NULL);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
			m_IndicesCount = 0;
		}


	}
}