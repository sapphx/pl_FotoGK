#pragma once

#include "Math.h"
#include "Shape.h"

class Sphere : public Shape
{
public:
	Vector	center;
	float	radius;

	Sphere();
	Sphere(Vector cent, float R, LightIntensity Color = LightIntensity(1));
	~Sphere();

	//int		Intersect(Ray ray, float &distance);
	int		Intersect(Ray ray, float &distance, Vector& intesect1, Vector& intesect2 = Vector());

	virtual	int		IntersectDistance(Ray ray, float& distance);

	virtual Vector	GetNormal(Vector point) { 
													return (point - center).NormalizeProduct(); 
											}

	//const int		_MISS = 0;
	//const int		_ONE = 1;
	//const int		_DOUBLE = 2;

};

