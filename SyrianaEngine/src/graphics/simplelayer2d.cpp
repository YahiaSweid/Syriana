#include "simplelayer2d.h"

namespace syriana{
	namespace graphics{

		SimpleLayer2D::SimpleLayer2D(Shader* shader)
			:Layer2D(new Renderer2D, shader, maths::Matrix4::Orthographic(0, 800, 0, 800 / 16 * 9, -100, 100)){
			
		}

		SimpleLayer2D::~SimpleLayer2D(){}
	}
}