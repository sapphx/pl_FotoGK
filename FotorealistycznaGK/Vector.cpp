#include "Vector.h"
#include <cstdio>
#include <math.h>

#pragma region ////CONSTRUCTORS

Vector::Vector()
{
	x = y = z = 0;
}

Vector::Vector(float X, float Y, float Z) : x(X), y(Y), z(Z)
{
}

Vector::Vector(float X, float Y) : x(X), y(Y), z(0)
{
}

Vector::Vector(float all) : x(all), y(all), z(all)
{
}

Vector::Vector(const Vector &obj) : x(obj.x), y(obj.y), z(obj.z)
{
}

Vector::~Vector()
{
}

#pragma endregion

#pragma region ////FUNCTIONS

float	Vector::Length()
{
	return sqrtf(x*x + y*y + z*z);
}

float	Vector::LenghtSquared()
{
	return (x*x + y*y + z*z);
}

void	Vector::Normalize()
{
	float n = Length();
	if (n!=0)
	*this /= n;
}

Vector	Vector::NormalizeProduct()
{
	float n = Length();
	if (n != 0)
	//Vector vec = Vector(x,y,z);
	*this /= n;
	return Vector(*this);
}

float Vector::Dot(Vector v)
{
	return (x * v.x + y * v.y + z * v.z);
}

Vector Vector::Cross(Vector v)
{
	return Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

void Vector::Cross(Vector v1, Vector v2)
{
	x = v1.y*v2.z - v1.z*v2.y;
	y = v1.z*v2.x - v1.x*v2.z;
	z = v1.x*v2.y - v1.y*v2.x;
}

Vector Vector::Reflect(Vector normal)
{
	return *this - (2 * Dot(normal) *normal);
}

Vector Vector::ToVector()
{
	Vector p = Vector(x, y, z);
	return p;
}  

Vector Vector::Lerp(Vector v, float t)
{
	Vector vector = Vector();
	vector.x = x + t * (v.x - x);
	vector.y = y + t * (v.y - y);
	vector.z = z + t * (v.z - z);
	return vector;
}

#pragma endregion

#pragma region ////OPERATORS

Vector Vector::operator+()
{
	return *this;
}

Vector Vector::operator-()
{
	return Vector(-x, -y, -z);
}

Vector Vector::operator=(const Vector& other)
{
	x = other.x; 
	y = other.y; 
	z = other.z;
	return *this;
}

Vector	Vector::operator+ (const Vector& b) const
{
	return Vector(x + b.x, y + b.y, z + b.z);
}

Vector	Vector::operator- (const Vector& b) const
{
	return Vector(x - b.x, y - b.y, z - b.z);
}

Vector	Vector::operator* (const Vector& b) const
{
	return Vector(x * b.x, y * b.y, z * b.z);
}

Vector	Vector::operator/ (const Vector& b) const
{
	return Vector(x / b.x, y / b.y, z / b.z);
}

Vector	Vector::operator+=(const Vector& b)
{
	x += b.x; 
	y += b.y;
	z += b.z;
	return *this;
}

Vector	Vector::operator-=(const Vector& b)
{
	x -= b.x;
	y -= b.y;
	z -= b.z;
	return *this;
}

Vector	Vector::operator*=(const Vector& b)
{
	x *= b.x;
	y *= b.y;
	z *= b.z;
	return *this;
}

Vector	Vector::operator/=(const Vector& b)
{
	x /= b.x;
	y /= b.y;
	z /= b.z;
	return *this;
}

Vector	Vector::operator* (const float& b)
{
	return Vector(x * b, y * b, z * b);
}

Vector	Vector::operator* (const int& b)
{
	return Vector(x * b, y * b, z * b);
}

Vector	Vector::operator/ (const float& b)
{
	return Vector(x / b, y / b, z / b);
}

Vector	Vector::operator/ (const int& b)
{
	return Vector(x / b, y / b, z / b);
}

Vector	Vector::operator*=(const float& b)
{
	x *= b;
	y *= b;
	z *= b;
	return *this;
}

Vector	Vector::operator*=(const int& b)
{
	x *= b;
	y *= b;
	z *= b;
	return *this;
}

Vector	Vector::operator/=(const float& b)
{
	x /= b;
	y /= b;
	z /= b;
	return *this;
}

Vector	Vector::operator/=(const int& b)
{
	x /= b;
	y /= b;
	z /= b;
	return *this;
}

Vector	operator* (const float& a, const Vector b)
{
	return Vector(a * b.x, a * b.y, a * b.z);
}

Vector	operator* (const int& a, const Vector b)
{
	return Vector(a * b.x, a * b.y, a * b.z);
}

#pragma endregion

#pragma region ////MISC

void	Vector::Print()
{
	std::printf("%f, %f, %f", x, y, z);
}

void	Vector::PrintNL()
{
	std::printf("%f, %f, %f\n", x, y, z);
}

#pragma endregion
