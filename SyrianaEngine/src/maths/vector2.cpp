#include "vector2.h"


namespace syriana{
	namespace maths{
		Vector2::Vector2(){
			x = 0.f;
			y = 0.f;
		}

		Vector2::Vector2(const float x, const float y){
			this->x = x;
			this->y = y;
		}

		Vector2& Vector2::Add(const Vector2& other){
			this->x += other.x;
			this->y += other.y;
			return *this;
		}

		Vector2& Vector2::Subtract(const Vector2& other){
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}

		Vector2& Vector2::Multiply(const Vector2& other){
			this->x *= other.x;
			this->y *= other.y;
			return *this;
		}

		Vector2& Vector2::Divide(const Vector2& other){
			this->x /= other.x;
			this->y /= other.y;
			return *this;
		}

		double Vector2::Length(){
			return sqrt(this->x * this->x + this->y * this->y);
		}

		double Vector2::LengthSqr(){
			return (this->x * this->x + this->y * this->y);
		}

		std::ostream& operator<<(std::ostream& stream, Vector2& vector){
			stream << "Vector2D (" << vector.x << "," << vector.y << ")";
			return stream;
		}

	}
}