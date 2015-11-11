#include "LightIntensity.h"
#include <cstdio>

#pragma region ////CONSTRUCTORS

LightIntensity::LightIntensity() : r(0), g(0), b(0) {}

LightIntensity::LightIntensity(float	R, float	G, float	B) : r(R), g(G), b(B) {}

LightIntensity::LightIntensity(float	all) : r(all), g(all), b(all) {}

LightIntensity::~LightIntensity() {}

#pragma endregion

#pragma region ////OPERATORS

void	LightIntensity::operator() (float R, float G, float B)
{
	r = R; g = G; b = B;
}

LightIntensity	LightIntensity::operator+(LightIntensity &li)
{
	return LightIntensity(r + li.r, g + li.g, b + li.b);
}

LightIntensity	LightIntensity::operator-(LightIntensity &li)
{
	return LightIntensity(r - li.r, g - li.g, b - li.b);
}

LightIntensity	LightIntensity::operator/(float num)
{
	return LightIntensity(r / num, g / num, b / num);
}

LightIntensity	LightIntensity::operator*(LightIntensity &li)
{
	return LightIntensity(r * li.r, g * li.g, b * li.b);
}

LightIntensity	LightIntensity::operator+=(LightIntensity &li)
{
	r += li.r;
	g += li.g;
	b += li.b;
	return *this;
}

LightIntensity	LightIntensity::operator-=(LightIntensity &li)
{
	r -= li.r;
	g -= li.g;
	b -= li.b;
	return *this;
}

LightIntensity	LightIntensity::operator*=(float num)
{
	r *= num;
	g *= num;
	b *= num;
	return *this;
}

LightIntensity	LightIntensity::operator/=(float num)
{
	r /= num;
	g /= num;
	b /= num;
	return *this;
}


LightIntensity	operator*(float num, LightIntensity &li)
{
	return	LightIntensity(li.r * num, li.g * num, li.b * num);
}

LightIntensity	operator*(LightIntensity &li, float num)
{
	return	LightIntensity(li.r * num, li.g * num, li.b * num);
}

#pragma endregion

#pragma region ////FUNCTIONS

void LightIntensity::Add(double R, double G, double B)
{
	r += R;
	g += G;
	b += B;
}

void	LightIntensity::Print()
{
	std::printf("%f, %f, %f", r, g, b);
}

void	LightIntensity::PrintNL()
{
	std::printf("%f, %f, %f\n", r, g, b);
}

LightIntensity	LightIntensity::GetColorM16(int iter)
{
	LightIntensity li[16] = {	LightIntensity(1,1,1), LightIntensity(1,0,0), LightIntensity(0,1,0), LightIntensity(0,0,1),
								LightIntensity(1,1,0), LightIntensity(1,0,1), LightIntensity(0,1,1), LightIntensity(0.5f,0.5f,0.5f),
								LightIntensity(0.75f,0.75f,0.75f), LightIntensity(1,0.5f,0.5f), LightIntensity(0.5f,1,0.5f), LightIntensity(0.5f,0.5f,1),
								LightIntensity(1,1,0.5f), LightIntensity(1,0.5f,1), LightIntensity(0.5f,1,1), LightIntensity(0.5f,0,0.5f) };
	return LightIntensity(li[iter]);
}

#pragma endregion