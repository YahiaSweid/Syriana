#pragma once

#include "vector3.h"
#include "vector4.h"

namespace syriana{
	namespace maths{

		struct Matrix4{
		public:
			float elements[16];

			Matrix4();
			Matrix4(const float diagonal);

			static Matrix4 Identity();

			Matrix4& Multiply(const Matrix4& other);
			friend Matrix4 operator*(Matrix4 left, const Matrix4& right);
			Matrix4& operator*=(const Matrix4& other);

			Vector3 Multiply(const Vector3& other);
			Vector4 Matrix4::Multiply(const Vector4& other);

			friend Vector3 operator*(Matrix4 left, const Vector3& right);
			friend Vector4 operator*(Matrix4 left, const Vector4& right);



			static Matrix4 Orthographic(float left, float right, float top, float bottom, float near, float far);

			static Matrix4 Translate(const Vector3& translate);
			static Matrix4 RotateZ(float angle);
			static Matrix4 Scale(const Vector3& scale);

		};

	}
}