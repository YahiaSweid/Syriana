#include "vector3.h"


namespace syriana{
	namespace maths{
		Vector3::Vector3(){
			x = 0.f;
			y = 0.f;
			z = 0.f;
		}

		Vector3::Vector3(const float x, const float y, const float z){
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3& Vector3::Add(const Vector3& other){
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}

		Vector3& Vector3::Subtract(const Vector3& other){
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}

		Vector3& Vector3::Multiply(const Vector3& other){
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			return *this;
		}

		Vector3& Vector3::Divide(const Vector3& other){
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			return *this;
		}


		std::ostream& operator<<(std::ostream& stream, Vector3& Vector3){
			stream << "Vector3D (" << Vector3.x << "," << Vector3.y << "," << Vector3.z << ")";
			return stream;
		}

	}
}