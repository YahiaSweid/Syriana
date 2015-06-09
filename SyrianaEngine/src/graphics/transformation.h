#pragma once

#include <vector>
#include "../maths/matrix4.h"

namespace syriana{
	namespace graphics{

		class Transformation{
		public:
			std::vector<maths::Matrix4> m_TransformationStack;
			maths::Matrix4* m_TransformationBack;
		public:
			Transformation();
			void PushTransformation(maths::Matrix4 transform);
			void PopTransformation();
		};

	}
}