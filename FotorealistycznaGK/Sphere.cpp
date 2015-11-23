#include "Sphere.h"

#include <math.h>

Sphere::Sphere() : Shape(), center(Vector()), radius(0.0f)
{

}

Sphere::Sphere(Vector cent, float R, LightIntensity Color, int _MaterialID) : Shape(Color, _MaterialID), center(cent), radius(R)
{

}

Sphere::~Sphere()
{
}

int		Sphere::IntersectDistance(Ray ray, float &distance)
{
	Vector v = ray.origin - center;
	float b = -v.Dot(ray.direction);
	float det = (b * b) - v.Dot(v) + radius;
	int retval = __HIT_MISS;
	if (det > 0)
	{
		det = sqrtf(det);
		float i1 = b - det;
		float i2 = b + det;
		if (i2 > 0)
		{
			if (i1 < 0)
			{
				if (i2 < distance)
				{
					distance = i2;
					retval = __HIT_ONE;
				}
			}
			else
			{
				if (i1 < distance)
				{
					distance = i1;
					retval = __HIT_DOUBLE;
				}
			}
		}
	}
	return retval;
}

void Sphere::ComputeUV(int & u, int & v, Vector hit, int size)
{
	Vector local = Vector(hit - center);
	float theta = acos(local.y);
	float phi = atan2(local.x, local.z);
	if (phi < 0.0)
		phi += _2PI;
	// nastêpnie, konwertujemy theta i phi do (u, v) w [0, 1] X [0, 1]
	float uF = phi * _I2PI;
	float vF = 1.0 - theta * _IPI;
	// na koñcu, przekszta³camy u oraz v wspó³rzêdnych texela
	u = (int)((size - 1) * uF); // kolumna jest poziomo
	v = (int)((size - 1) * vF);
}


int		Sphere::Intersect(Ray ray, float &distance, Vector& intesect1, Vector& intesect2)
{
	Vector v = ray.origin - center;
	float b = -v.Dot(ray.direction);
	float det = (b * b) - v.Dot(v) + radius;
	int retval = __HIT_MISS;
	if (det > 0)
	{
		det = sqrtf(det);
		float i1 = b - det;
		float i2 = b + det;
		if (i2 > 0)
		{
			if (i1 < 0)
			{
				if (i2 < distance)
				{
					distance = i2;
					intesect1 = Vector(ray.direction * i2 + ray.origin);
					retval = __HIT_ONE;
				}
			}
			else
			{
				if (i1 < distance)
				{
					distance = i1;
					intesect1 = Vector(ray.direction * i2 + ray.origin);
					intesect2 = Vector(ray.direction * i1 + ray.origin);
					retval = __HIT_DOUBLE;
				}
			}
		}
	}
	return retval;
}