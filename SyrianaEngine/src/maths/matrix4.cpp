#include "matrix4.h"

namespace syriana{
	namespace maths{

		Matrix4::Matrix4(){
			for (int i = 0; i < 16; i++)
				elements[i] = 0.f;
		}

		Matrix4::Matrix4(const float diagonal){
			for (int i = 0; i < 16; i++)
				elements[i] = 0.f;

			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		Matrix4 Matrix4::Identity(){
			return Matrix4(1.f);
		}

		Matrix4& Matrix4::Multiply(const Matrix4& other){
			float data[16];
			for (int row = 0; row < 4; row++){
				for (int column = 0; column < 4; column++){
					float sum = 0.f;
					for (int element = 0; element < 4; element++){
						sum += elements[column + element * 4] * other.elements[element + row * 4];
					}
					data[row + column * 4] = sum;
				}
			}
			memcpy(elements, data, 16 * 4);
			return *this;
		}

		Vector3 Matrix4::Multiply(const Vector3& other){
			return Vector3(
				elements[0] * other.x + elements[4] * other.y + elements[8] * other.z + elements[12],
				elements[1] * other.x + elements[5] * other.y + elements[9] * other.z + elements[13],
				elements[2] * other.x + elements[6] * other.y + elements[10] * other.z + elements[14]
			);
		}

		Vector4 Matrix4::Multiply(const Vector4& other){
			return Vector4(
				elements[0] * other.x + elements[4] * other.y + elements[8] * other.z + elements[12] * other.w,
				elements[1] * other.x + elements[5] * other.y + elements[9] * other.z + elements[13] * other.w,
				elements[2] * other.x + elements[6] * other.y + elements[10] * other.z + elements[14] * other.w,
				elements[3] * other.x + elements[7] * other.y + elements[11] * other.z + elements[15] * other.w
				);
		}

		Matrix4 operator*(Matrix4 left, const Matrix4& right){
			return left.Multiply(right);
		}

		Vector3 operator*(Matrix4 left, const Vector3& right){
			return left.Multiply(right);
		}

		Vector4 operator*(Matrix4 left, const Vector4& right){
			return left.Multiply(right);
		}

		Matrix4& Matrix4::operator*=(const Matrix4& other){
			return Multiply(other);
		}

		Matrix4 Matrix4::Orthographic(float left, float right, float top, float bottom, float near, float far){
			Matrix4 result(1.f);
			result.elements[0 + 0 * 4] = 2.f / (right - left);
			result.elements[1 + 1 * 4] = 2.f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.f / (near - far);

			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		Matrix4 Matrix4::Translate(const Vector3& translation){
			Matrix4 result(1.f);
			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;
			return result;
		}



		Matrix4 Matrix4::Scale(const Vector3& scale){
			Matrix4 result(1.f);
			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;
			return result;
		}

	}
}