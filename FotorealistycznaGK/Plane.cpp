#include "Plane.h"


Plane::Plane() : Shape() {}

Plane::Plane(Vector Normal, float Distance, LightIntensity Color) : Shape(Color), normal(Normal), origin(Vector(0)), distance(Distance) {}

Plane::Plane(Vector Normal, Vector Origin, LightIntensity Color) : Shape(Color), normal(Normal), origin(Origin)
{
	distance = Normal.Dot(Origin);
}

//Plane::Plane(Vector Origin, Vector Normal, float Distance) : origin(Origin), normal(Normal), distance(Distance) {}


Plane::~Plane()
{
}


int		Plane::Intersect(Ray ray, Vector& intersection, float& distance)
{
	float VdotN = ray.direction.Dot(normal);
	if (VdotN == 0) 
	{
		distance = 0;
		return __HIT_ALLIGNED;
	}
	
	float t = (this->distance - ray.origin.Dot(normal)) / VdotN;
	if (t > 0)
	{
		intersection = ray.origin + t*ray.direction;
		distance = t;
		return __HIT_ONE;
	}
	else
	{
		return __HIT_MISS;
	}

}


int		Plane::IntersectDistance(Ray ray, float& distance)
{
	float VdotN = ray.direction.Dot(normal);
	if (VdotN == 0)
	{
		distance = 0;
		return __HIT_ALLIGNED;
	}

	float t = -(ray.origin.Dot(normal) + distance) / VdotN;
	if (t > 0)
	{
		distance = t;
		return __HIT_ONE;
	}
	else
	{
		return __HIT_MISS;
	}
}