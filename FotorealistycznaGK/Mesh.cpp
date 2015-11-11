#include "Mesh.h"



Mesh::Mesh() : Shape()
{
	triangles = vector<Triangle*>();
}

Mesh::Mesh(LightIntensity Color) : Shape()
{
	color = Color;
	triangles = vector<Triangle*>();
}


Mesh::~Mesh()
{
	for (int i = 0; i < triangles.size(); i++)
	{
		delete triangles[i];
	}
}


int	Mesh::IntersectDistance(Ray ray, float& distance)
{
	float initialDistance = distance;
	float minDistance = distance;

	//for each (Triangle* tri in triangles)
	//{
	//	if (tri->IntersectDistance(ray, distance) == __HIT_ONE)
	//	{
	//		if (distance < minDistance)
	//		{
	//			minDistance = distance;
	//		}
	//	}
	
	for (int i = 0; i < triangles.size(); i++)
	{
		distance = initialDistance;
		if (triangles[i]->IntersectDistance(ray, distance) == __HIT_ONE)
		{
			if (distance < minDistance)
			{
				minDistance = distance;
				innerColor = triangles[i]->color;
			}
		}
	}

	if (minDistance < initialDistance)
	{
		distance = minDistance;
		return __HIT_ONE;
	}
	else
	{
		distance == initialDistance;
		return __HIT_MISS;
	}

}