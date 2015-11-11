#pragma once

#include "Math.h"
#include "Shape.h"

class Plane : public Shape
{
public:
	Vector	origin;
	Vector	normal;
	float	distance;

	Plane();
	Plane(Vector Normal, float Distance = 0, LightIntensity Color = LightIntensity(1));
	Plane(Vector Normal, Vector Origin, LightIntensity Color = LightIntensity(1));
	//Plane(Vector Origin, Vector Normal, float Distance = 0);
	~Plane();

	int		Intersect(Ray ray, Vector& intersection, float& distance);
	int		IntersectDistance(Ray ray, float& distance);
};

