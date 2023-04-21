#pragma once

#include <cmath>

class Vector2
{
public:
	float x;
	float y;

	Vector2(float x = 0, float y = 0);
	~Vector2();

	bool operator == (const Vector2& otherVector);
	bool operator != (const Vector2& otherVector);

	Vector2& operator + (const Vector2& otherVector);
	Vector2& operator - (const Vector2& otherVector);

	double Distance(const Vector2& otherVector);
};