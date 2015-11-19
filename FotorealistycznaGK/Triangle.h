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
	Vector2	ta, tb, tc;

	Triangle();
	Triangle(Vector A, Vector B, Vector C);
	Triangle(Vector A, Vector B, Vector C, Vector N);
	Triangle(Vector A, Vector B, Vector C, Vector N, LightIntensity Color);
	Triangle(Vector A, Vector B, Vector C, Vector N, LightIntensity Color, Vector2 TexA, Vector2 TexB, Vector2 TexC);
	~Triangle();

	virtual	int		IntersectDistance(Ray ray, float& distance);
	virtual	void	ComputeUV(int &u, int &v, Vector hit, int size);
	//Shape* CTriangle::CountCrossPoint(CRay* ray, CVector3& crosspoint, float &odleglosc)

	void Barycentric(Vector p, Vector a, Vector b, Vector c, float &u, float &v, float &w)
	{
		Vector v0 = b - a, v1 = c - a, v2 = p - a;
		float d00 = v0.Dot(v0);
		float d01 = v0.Dot(v1);
		float d11 = v1.Dot(v1);
		float d20 = v2.Dot(v0);
		float d21 = v2.Dot(v1);
		float denom = 1.0f / ( d00 * d11 - d01 * d01 );
		v = (d11 * d20 - d01 * d21) * denom;
		w = (d00 * d21 - d01 * d20) * denom;
		u = 1.0f - v - w;
	}
};

