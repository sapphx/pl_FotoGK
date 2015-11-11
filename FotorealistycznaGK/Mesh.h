#pragma once

#include <vector>
#include "Triangle.h"

using namespace std;

class Mesh : public Shape
{
public:
	std::vector<Triangle*> triangles;

	Mesh();
	Mesh(LightIntensity Color);
	~Mesh();

	virtual	int		IntersectDistance(Ray ray, float& distance);
};

