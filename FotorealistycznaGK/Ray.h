#pragma once

#include "Vector.h"

class Ray
{
public:
	Vector	origin,
			direction,
			destination;
	float	distance;

	Ray();
	Ray(Vector Origin, float Distance, Vector Direction);
	Ray(Vector Origin, Vector Destination);
	~Ray();
};

