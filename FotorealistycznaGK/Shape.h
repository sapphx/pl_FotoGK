#pragma once

#include "Ray.h"
#include "LightIntensity.h"

class Shape
{
public:
	LightIntensity	color;
	LightIntensity	innerColor;
	
	Shape() : color(LightIntensity(0)), innerColor(LightIntensity(0)) {}
	Shape(LightIntensity Color) : color(Color), innerColor(Color) {}
	~Shape();

	virtual	int		IntersectDistance(Ray ray, float& distance) { return -1; }
	LightIntensity	GetColor()	{ return color; }

};
