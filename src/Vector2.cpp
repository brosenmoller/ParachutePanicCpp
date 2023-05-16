#include "Vector2.hpp"

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

bool Vector2::operator==(const Vector2& otherVector)
{
	if (x == otherVector.x && y == otherVector.y) { return true; }
	else { return false; }
}

bool Vector2::operator!=(const Vector2& otherVector)
{
	if (x != otherVector.x || y != otherVector.y) { return true; }
	else { return false; }
}

Vector2& Vector2::operator+(const Vector2& otherVector)
{
	this->x += otherVector.x;
	this->y += otherVector.y;

	return *this;
}

Vector2& Vector2::operator-(const Vector2& otherVector)
{
	this->x -= otherVector.x;
	this->y -= otherVector.y;

	return *this;
}

Vector2 Vector2::Normalized()
{
	float magnitude = Magnitude();
	return Vector2(x / magnitude, y / magnitude);
}

void Vector2::Normalize()
{
	float magnitude = Magnitude();
	x /= magnitude;
	y /= magnitude;
}



float Vector2::Distance(const Vector2& otherVector)
{
	return sqrt(pow(otherVector.x - x, 2) + pow(otherVector.y - y, 2));
}

float Vector2::SqrDistance(const Vector2& otherVector)
{
	return pow(otherVector.x - x, 2) + pow(otherVector.y - y, 2);
}

float Vector2::DotProduct(const Vector2& otherVector)
{
	return x * otherVector.x + y * otherVector.y;
}

float Vector2::Magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector2::SqrMagnitude()
{
	return pow(x, 2) + pow(y, 2);
}
