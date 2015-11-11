#include "Triangle.h"


Triangle::Triangle()
{
}


Triangle::Triangle(Vector A, Vector B, Vector C) : a(A), b(B), c(C)
{
	n = (b - a).Cross(c - a);
	n.Normalize();
}

Triangle::Triangle(Vector A, Vector B, Vector C, Vector N) : a(A), b(B), c(C)
{
	n = N.NormalizeProduct();
}

Triangle::Triangle(Vector A, Vector B, Vector C, Vector N, LightIntensity Color) : Shape(), a(A), b(B), c(C)
{
	n = N.NormalizeProduct();
	color = (Color);
	innerColor = (Color);
}

Triangle::~Triangle()
{
}


int		Triangle::IntersectDistance(Ray ray, float& distance)
{
	Plane	p = Plane(n, a);//(a + b + c)*0.33333333333f);
	Vector	crosspoint;

	if (p.Intersect(ray, crosspoint, distance) == __HIT_MISS)
	{
		return __HIT_MISS;
	}

	Vector	fa, fb, fc;
	Vector	x;

	fa = a - crosspoint;
	fb = b - crosspoint;
	fc = c - crosspoint;

	x.Cross(fa, fb);
	if (x.Dot(p.normal) < MINUS_ZERO)
	{
		return __HIT_MISS;
	}

	x.Cross(fb, fc);
	if (x.Dot(p.normal) < MINUS_ZERO)
	{
		return __HIT_MISS;
	}

	x.Cross(fc, fa);
	if (x.Dot(p.normal) < MINUS_ZERO)
	{
		return __HIT_MISS;
	}

	return __HIT_ONE;

}