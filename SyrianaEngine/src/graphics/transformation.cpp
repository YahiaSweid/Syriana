#include "transformation.h"

namespace syriana{
	namespace graphics{

		Transformation::Transformation(){
			m_TransformationStack.push_back(maths::Matrix4::Identity());
			m_TransformationBack = &m_TransformationStack.back();
		}
		
		void Transformation::PushTransformation(maths::Matrix4 transform){
			m_TransformationStack.push_back(transform);
			m_TransformationBack = &m_TransformationStack.back();
		}

		void Transformation::PopTransformation(){
			if (m_TransformationStack.size() > 1){
				m_TransformationStack.pop_back();
				m_TransformationBack = &m_TransformationStack.back();
			}
		}

	}
}