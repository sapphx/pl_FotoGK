#pragma once
class Vector
{
public:
	float x, y, z;
	
	Vector();
	Vector(float X, float Y, float Z);
	Vector(float X, float Y);
	Vector(float all);
	Vector(const Vector &obj);

	~Vector();

	//FUNCTIONS

	float	Length();
	float	LenghtSquared();

	void	Normalize();
	Vector	NormalizeProduct();

	float	Dot(Vector v);
	Vector	Cross(Vector v);
	void	Cross(Vector v1, Vector v2);

	Vector	Reflect(Vector normal);
	Vector	ToVector();
	Vector	Lerp(Vector v, float t);

	//OPERATORS

	Vector	operator+ ();
	Vector	operator- ();
	Vector	operator= (const Vector& other);
	Vector	operator+ (const Vector& b) const;
	Vector	operator- (const Vector& b) const;
	Vector	operator* (const Vector& b) const;
	Vector	operator/ (const Vector& b) const;
	Vector	operator+=(const Vector& b);
	Vector	operator-=(const Vector& b);
	Vector	operator*=(const Vector& b);
	Vector	operator/=(const Vector& b);

	Vector	operator* (const float& b);
	Vector	operator* (const int& b);
	Vector	operator/ (const float& b);
	Vector	operator/ (const int& b);
	Vector	operator*=(const float& b);
	Vector	operator*=(const int& b);
	Vector	operator/=(const float& b);
	Vector	operator/=(const int& b);

	friend	Vector	operator* (const float& a, const Vector b);
	friend	Vector	operator* (const int& a, const Vector b);

	//MISC

	void	Print();
	void	PrintNL();

};




