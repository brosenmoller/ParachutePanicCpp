#include "Vector2.hpp"
#include "LogManager.hpp"

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

bool Vector2::operator==(const Vector2& otherVector) const
{
	if (x == otherVector.x && y == otherVector.y) { return true; }
	else { return false; }
}

bool Vector2::operator!=(const Vector2& otherVector) const
{
	if (x != otherVector.x || y != otherVector.y) { return true; }
	else { return false; }
}

Vector2 Vector2::operator+(const Vector2& otherVector) const
{
	return Vector2(x + otherVector.x, y + otherVector.y);
}

Vector2 Vector2::operator-(const Vector2& otherVector) const
{
	return Vector2(x - otherVector.x, y - otherVector.y);
}

Vector2 Vector2::operator*(const float& scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

Vector2& Vector2::operator+=(const Vector2& otherVector)
{
	this->x += otherVector.x;
	this->y += otherVector.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& otherVector)
{
	this->x -= otherVector.x;
	this->y -= otherVector.y;

	return *this;
}

Vector2 Vector2::Normalized() const
{
	if (x == 0 && y == 0) { return Vector2::Zero(); }

	float magnitude = Magnitude();
	return Vector2(x / magnitude, y / magnitude);
}

Vector2& Vector2::Normalize()
{
	if (x == 0 && y == 0) { return *this; }

	float magnitude = Magnitude();
	this->x /= magnitude;
	this->y /= magnitude;

	return *this;
}

Vector2 Vector2::Inversed() const
{
	return Vector2(x * -1, y * -1);
}

Vector2& Vector2::Inverse()
{
	this->x *= -1;
	this->y *= -1;

	return *this;
}


float Vector2::Distance(const Vector2& otherVector) const
{
	return sqrt(pow(otherVector.x - x, 2) + pow(otherVector.y - y, 2));
}

float Vector2::SqrDistance(const Vector2& otherVector) const
{
	return pow(otherVector.x - x, 2) + pow(otherVector.y - y, 2);
}

float Vector2::DotProduct(const Vector2& otherVector) const
{
	return x * otherVector.x + y * otherVector.y;
}

float Vector2::Magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector2::SqrMagnitude() const
{
	return pow(x, 2) + pow(y, 2);
}
