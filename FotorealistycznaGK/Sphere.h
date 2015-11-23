#pragma once

#include <math.h>

#include "Math.h"
#include "Shape.h"

#define _PI   3.14159265359f
#define _2PI  6.28318530718f
#define _IPI  0.31830988618f
#define _I2PI 0.15915494309f

class Sphere : public Shape
{
public:
	Vector	center;
	float	radius;

	Sphere();
	Sphere(Vector cent, float R, LightIntensity Color = LightIntensity(1), int _MaterialID = 0);
	~Sphere();

	//int		Intersect(Ray ray, float &distance);
	int		Intersect(Ray ray, float &distance, Vector& intesect1, Vector& intesect2 = Vector());

	virtual	int		IntersectDistance(Ray ray, float& distance);

	virtual Vector	GetNormal(Vector point) { return (point - center).NormalizeProduct(); }

	virtual	void	ComputeUV(int &u, int &v, Vector hit, int size);



	//const int		_MISS = 0;
	//const int		_ONE = 1;
	//const int		_DOUBLE = 2;

};

