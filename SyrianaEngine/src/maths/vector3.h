#pragma once

#include <iostream>

namespace syriana{
	namespace maths{

		struct Vector3{
		public:
			float x, y, z;

			Vector3();
			Vector3(const float x, const float y, const float z);

			Vector3& Add(const Vector3& other);
			Vector3& Subtract(const Vector3& other);
			Vector3& Multiply(const Vector3& other);
			Vector3& Divide(const Vector3& other);

			double Length();
			double LengthSqr();

			inline friend Vector3 operator + (Vector3 left, Vector3& right){ return left.Add(right); }
			inline friend Vector3 operator-(Vector3 left, Vector3& right){ return left.Subtract(right); }
			inline friend Vector3 operator*(Vector3 left, Vector3& right){ return left.Multiply(right); }
			inline friend Vector3 operator/(Vector3 left, Vector3& right){ return left.Divide(right); }

			inline Vector3 operator += (Vector3& other){ return Add(other); }
			inline Vector3 operator-=(Vector3& other){ return Subtract(other); }
			inline Vector3 operator*=(Vector3& other){ return Multiply(other); }
			inline Vector3 operator/=(Vector3& other){ return Divide(other); }

			inline bool operator==(Vector3& other){ return (this->x == other.x && this->y == other.y && this->z == other.z); }
			inline bool operator!=(Vector3& other){ return !(*this == other); }

			friend std::ostream& operator<<(std::ostream& stream, Vector3& vector);

		};

	}
}