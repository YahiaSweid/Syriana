#pragma once

#include <iostream>

namespace syriana{
	namespace maths{

		struct Vector4 {
		public:
			float x, y, z, w;

			Vector4();
			Vector4(const float x, const float y, const float z, const float w);

			Vector4& Add(const Vector4& other);
			Vector4& Subtract(const Vector4& other);
			Vector4& Multiply(const Vector4& other);
			Vector4& Divide(const Vector4& other);

			inline friend Vector4 operator+(Vector4 left, Vector4& right){ return left.Add(right); }
			inline friend Vector4 operator-(Vector4 left, Vector4& right){ return left.Subtract(right); }
			inline friend Vector4 operator*(Vector4 left, Vector4& right){ return left.Multiply(right); }
			inline friend Vector4 operator/(Vector4 left, Vector4& right){ return left.Divide(right); }

			inline Vector4 operator+=(Vector4& other){ return Add(other); }
			inline Vector4 operator-=(Vector4& other){ return Subtract(other); }
			inline Vector4 operator*=(Vector4& other){ return Multiply(other); }
			inline Vector4 operator/=(Vector4& other){ return Divide(other); }

			inline bool operator==(Vector4& other){ return (this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w); }
			inline bool operator!=(Vector4& other){ return !(*this == other); }

			friend std::ostream& operator<<(std::ostream& stream, Vector4& vector);

		};

	}
}