#include "vector4.h"


namespace syriana{
	namespace maths{
		Vector4::Vector4(){
			x = 0.f;
			y = 0.f;
			z = 0.f;
			w = 0.f;
		}

		Vector4::Vector4(const float x, const float y, const float z, const float w){
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = z;
		}

		Vector4& Vector4::Add(const Vector4& other){
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
			return *this;
		}

		Vector4& Vector4::Subtract(const Vector4& other){
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
			return *this;
		}

		Vector4& Vector4::Multiply(const Vector4& other){
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;
			return *this;
		}

		Vector4& Vector4::Divide(const Vector4& other){
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;
			return *this;
		}


		std::ostream& operator<<(std::ostream& stream, Vector4& Vector4){
			stream << "Vector4D (" << Vector4.x << "," << Vector4.y << "," << Vector4.z << ")";
			return stream;
		}

	}
}