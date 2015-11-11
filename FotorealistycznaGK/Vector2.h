#pragma once
class Vector2
{
public:
	float x, y;

	Vector2();
	Vector2(float X, float Y);
	Vector2(float all);
	Vector2(const Vector2 &obj);

	~Vector2();

	//FUNCTIONS

	float	Length();
	float	LenghtSquared();

	void	Normalize();
	Vector2	NormalizeProduct();

	float	Dot(Vector2 v);

	Vector2	Reflect(Vector2 normal);
	Vector2	ToVector();
	Vector2	Lerp(Vector2 v, float t);

	//OPERATORS

	Vector2	operator+ ();
	Vector2	operator- ();
	Vector2	operator= (const Vector2& other);
	Vector2	operator+ (const Vector2& b) const;
	Vector2	operator- (const Vector2& b) const;
	Vector2	operator* (const Vector2& b) const;
	Vector2	operator/ (const Vector2& b) const;
	Vector2	operator+=(const Vector2& b);
	Vector2	operator-=(const Vector2& b);
	Vector2	operator*=(const Vector2& b);
	Vector2	operator/=(const Vector2& b);

	Vector2	operator* (const float& b);
	Vector2	operator* (const int& b);
	Vector2	operator/ (const float& b);
	Vector2	operator/ (const int& b);
	Vector2	operator*=(const float& b);
	Vector2	operator*=(const int& b);
	Vector2	operator/=(const float& b);
	Vector2	operator/=(const int& b);

	friend	Vector2	operator* (const float& a, const Vector2 b);
	friend	Vector2	operator* (const int& a, const Vector2 b);

	//MISC

	void	Print();
	void	PrintNL();
};

