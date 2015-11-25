#pragma once

#include "Ray.h"
#include "LightIntensity.h"

class Shape
{
public:
	LightIntensity	color;
	LightIntensity	innerColor;
	int				materialId;

	Shape() : color(LightIntensity(0)), innerColor(LightIntensity(0)) {}
	Shape(LightIntensity Color, int _MaterialID = 0) : color(Color), innerColor(Color), materialId(_MaterialID) {}
	~Shape();

	virtual	int		IntersectDistance(Ray ray, float& distance) { return -1; }
	virtual	int		IntersectWithBackfaces(Ray ray, Vector& intersection) { return -1; }
	LightIntensity	GetColor()	{ return color; }

	virtual Vector	GetNormal(Vector point) { return Vector(0, 0, 1); }
	virtual	void	ComputeUV(int &u, int &v, Vector hit, int size) {}
};

