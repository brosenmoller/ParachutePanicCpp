#pragma once

#include <cmath>

class Vector2
{
public:
	float x;
	float y;

	Vector2(float x = 0, float y = 0);
	~Vector2() {}

	const static Vector2 Right() { return Vector2(1, 0); }
	const static Vector2 Left() { return Vector2(-1, 0); }
	const static Vector2 Up() { return Vector2(0, -1); }
	const static Vector2 Down() { return Vector2(0, 1); }
	const static Vector2 Zero() { return Vector2(0, 0); }

	bool operator == (const Vector2& otherVector) const;
	bool operator != (const Vector2& otherVector) const;

	Vector2 operator + (const Vector2& otherVector) const;
	Vector2 operator - (const Vector2& otherVector) const;
	Vector2 operator * (const float& scalar) const;
	Vector2& operator += (const Vector2& otherVector);
	Vector2& operator -= (const Vector2& otherVector);

	Vector2 Normalized() const;
	Vector2& Normalize();

	Vector2 Inversed() const;
	Vector2& Inverse();

	float Distance(const Vector2& otherVector) const;
	float SqrDistance(const Vector2& othervector) const;

	float DotProduct(const Vector2& othervector) const;

	float Magnitude() const;
	float SqrMagnitude() const;
};