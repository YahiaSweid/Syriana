#pragma once

#include "vector3.h"

namespace syriana{
	namespace maths{

		struct Matrix4{
		public:
			float elements[16];

			Matrix4();
			Matrix4(const float diagonal);

			Matrix4 Identity();

			Matrix4& Multiply(const Matrix4& other);
			friend Matrix4 operator*(Matrix4 left, const Matrix4& right);
			Matrix4& operator*=(const Matrix4& other);

			static Matrix4 Orthographic(float left, float right, float top, float bottom, float near, float far);

			static Matrix4 Translate(const Vector3& translate);
			static Matrix4 RotateZ(float angle);
			static Matrix4 Scale(const Vector3& scale);

		};

	}
}