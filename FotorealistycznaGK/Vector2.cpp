#include "Vector2.h"
#include <cstdio>
#include <math.h>

#pragma region ////CONSTRUCTORS

Vector2::Vector2()
{
	x = y = 0;
}

Vector2::Vector2(float X, float Y) : x(X), y(Y)
{
}

Vector2::Vector2(float all) : x(all), y(all)
{
}

Vector2::Vector2(const Vector2 &obj) : x(obj.x), y(obj.y)
{
}

Vector2::~Vector2()
{
}

#pragma endregion

#pragma region ////FUNCTIONS

float	Vector2::Length()
{
	return sqrtf(x*x + y*y);
}

float	Vector2::LenghtSquared()
{
	return (x*x + y*y);
}

void	Vector2::Normalize()
{
	float n = Length();
	if (n != 0)
		*this /= n;
}

Vector2	Vector2::NormalizeProduct()
{
	float n = Length();
	if (n != 0)
		return *this /= n;
}

float Vector2::Dot(Vector2 v)
{
	return (x * v.x + y * v.y);
}

Vector2 Vector2::Reflect(Vector2 normal)
{
	return *this - (2 * Dot(normal) *normal);
}

Vector2 Vector2::ToVector()
{
	Vector2 p = Vector2(x, y);
	return p;
}

Vector2 Vector2::Lerp(Vector2 v, float t)
{
	Vector2 vector = Vector2();
	vector.x = x + t * (v.x - x);
	vector.y = y + t * (v.y - y);
	return vector;
}

#pragma endregion

#pragma region ////OPERATORS

Vector2 Vector2::operator+()
{
	return *this;
}

Vector2 Vector2::operator-()
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator=(const Vector2& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vector2	Vector2::operator+ (const Vector2& b) const
{
	return Vector2(x + b.x, y + b.y);
}

Vector2	Vector2::operator- (const Vector2& b) const
{
	return Vector2(x - b.x, y - b.y);
}

Vector2	Vector2::operator* (const Vector2& b) const
{
	return Vector2(x * b.x, y * b.y);
}

Vector2	Vector2::operator/ (const Vector2& b) const
{
	return Vector2(x / b.x, y / b.y);
}

Vector2	Vector2::operator+=(const Vector2& b)
{
	x += b.x;
	y += b.y;
	return *this;
}

Vector2	Vector2::operator-=(const Vector2& b)
{
	x -= b.x;
	y -= b.y;
	return *this;
}

Vector2	Vector2::operator*=(const Vector2& b)
{
	x *= b.x;
	y *= b.y;
	return *this;
}

Vector2	Vector2::operator/=(const Vector2& b)
{
	x /= b.x;
	y /= b.y;
	return *this;
}

Vector2	Vector2::operator* (const float& b)
{
	return Vector2(x * b, y * b);
}

Vector2	Vector2::operator* (const int& b)
{
	return Vector2(x * b, y * b);
}

Vector2	Vector2::operator/ (const float& b)
{
	return Vector2(x / b, y / b);
}

Vector2	Vector2::operator/ (const int& b)
{
	return Vector2(x / b, y / b);
}

Vector2	Vector2::operator*=(const float& b)
{
	x *= b;
	y *= b;
	return *this;
}

Vector2	Vector2::operator*=(const int& b)
{
	x *= b;
	y *= b;
	return *this;
}

Vector2	Vector2::operator/=(const float& b)
{
	x /= b;
	y /= b;
	return *this;
}

Vector2	Vector2::operator/=(const int& b)
{
	x /= b;
	y /= b;
	return *this;
}

Vector2	operator* (const float& a, const Vector2 b)
{
	return Vector2(a * b.x, a * b.y);
}

Vector2	operator* (const int& a, const Vector2 b)
{
	return Vector2(a * b.x, a * b.y);
}

#pragma endregion

#pragma region ////MISC

void	Vector2::Print()
{
	std::printf("%f, %f", x, y);
}

void	Vector2::PrintNL()
{
	std::printf("%f, %f\n", x, y);
}

#pragma endregion
