#include "layer2d.h"

namespace syriana{
	namespace graphics{

		Layer2D::Layer2D(Renderer2D* renderer, Shader* shader, maths::Matrix4 projectionMatrix):
			m_Renderer(renderer),m_Shader(shader),m_ProjectionMatrix(projectionMatrix){
			m_Shader->Enable();
			m_Shader->SetUniformMat4("projectionMatrix", projectionMatrix);
			m_Shader->Disable();
		}

		Layer2D::~Layer2D(){
			delete m_Renderer;
			for (int i = 0; i < m_Sprites.size(); i++)
				delete m_Sprites[i];
		}

		void Layer2D::Add(Sprite* sprite){
			m_Sprites.push_back(sprite);
		}

		void Layer2D::Render(){
			m_Shader->Enable();
			m_Renderer->Prepare();
			for (int i = 0; i < m_Sprites.size(); i++)
				m_Sprites[i]->Render(m_Renderer);
			m_Renderer->End();
			m_Renderer->Render();
		}

	}
}