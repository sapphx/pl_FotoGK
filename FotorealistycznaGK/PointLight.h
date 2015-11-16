#pragma once
#pragma once 

#include "Vector.h"
#include "LightIntensity.h"

class PointLight
{
public:
	Vector			position;
	LightIntensity	color;
	float			intensity;
	
	PointLight();
	PointLight(Vector _Position, LightIntensity _Light, float _Intensity);
	~PointLight();
};

