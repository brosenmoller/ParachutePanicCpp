#pragma once

#include <cmath>

class Vector2
{
public:
	float x;
	float y;

	Vector2(float x = 0, float y = 0);
	~Vector2() {}

	bool operator == (const Vector2& otherVector);
	bool operator != (const Vector2& otherVector);

	Vector2& operator + (const Vector2& otherVector);
	Vector2& operator - (const Vector2& otherVector);

	Vector2 Normalized();
	void Normalize();

	float Distance(const Vector2& otherVector);
	float SqrDistance(const Vector2& othervector);

	float DotProduct(const Vector2& othervector);

	float Magnitude();
	float SqrMagnitude();
};