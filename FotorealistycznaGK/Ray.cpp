#include "Ray.h"


Ray::Ray() : origin(Vector()), direction(Vector()), destination(Vector())
{
}

Ray::Ray(Vector Origin, float	Distance, Vector Direction) : origin(Origin), distance(Distance)
{
	direction = Direction.NormalizeProduct();
	destination = Vector(Origin + Distance * Direction);
}

Ray::Ray(Vector Origin, Vector Destination) : origin(Origin), destination(Destination)
{
	direction = (Destination - Origin).NormalizeProduct();
	distance = (Destination - Origin).Length();
}

Ray::~Ray()
{
}
