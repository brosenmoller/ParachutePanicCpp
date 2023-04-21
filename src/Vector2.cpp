#include "Vector2.hpp"

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{}

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

double Vector2::Distance(const Vector2& otherVector)
{
	return sqrt(pow(otherVector.x - x, 2) + pow(otherVector.y - y, 2));
}
