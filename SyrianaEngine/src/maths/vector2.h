#pragma once

#include <iostream>

namespace syriana{
	namespace maths{

		struct Vector2{
		public:
			float x, y;

			Vector2();
			Vector2(const float x, const float y);

			Vector2& Add(const Vector2& other);
			Vector2& Subtract(const Vector2& other);
			Vector2& Multiply(const Vector2& other);
			Vector2& Divide(const Vector2& other);

			double Length();
			double LengthSqr();

			inline friend Vector2 operator+(Vector2 left, Vector2& right){ return left.Add(right); }
			inline friend Vector2 operator-(Vector2 left, Vector2& right){ return left.Subtract(right); }
			inline friend Vector2 operator*(Vector2 left, Vector2& right){ return left.Multiply(right); }
			inline friend Vector2 operator/(Vector2 left, Vector2& right){ return left.Divide(right); }

			inline Vector2 operator+=(Vector2& other){ return Add(other); }
			inline Vector2 operator-=(Vector2& other){ return Subtract(other); }
			inline Vector2 operator*=(Vector2& other){ return Multiply(other); }
			inline Vector2 operator/=(Vector2& other){ return Divide(other); }

			inline bool operator==(Vector2& other){ return (this->x == other.x && this->y == other.y); }
			inline bool operator!=(Vector2& other){ return !(*this == other); }

			friend std::ostream& operator<<(std::ostream& stream, Vector2& vector);

		};

	}
}