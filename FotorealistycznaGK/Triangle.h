#pragma once

#include "Vector.h"
#include "Shape.h"
#include "Plane.h"

#define PLUS_ZERO	0.00001
#define MINUS_ZERO	-0.00001

class Triangle : public Shape
{
public:
	Vector	a, b, c;
	Vector	n;

	Triangle();
	Triangle(Vector A, Vector B, Vector C);
	Triangle(Vector A, Vector B, Vector C, Vector N);
	Triangle(Vector A, Vector B, Vector C, Vector N, LightIntensity Color);
	~Triangle();

	virtual	int		IntersectDistance(Ray ray, float& distance);
	//Shape* CTriangle::CountCrossPoint(CRay* ray, CVector3& crosspoint, float &odleglosc)
};

