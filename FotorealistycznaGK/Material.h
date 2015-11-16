#pragma once
#pragma once

#include "LightIntensity.h"

class Material
{
public:
	LightIntensity	ambient;
	LightIntensity	diffuse;
	LightIntensity	specular;
	int				specularPower;
	//float	kDiffuse;
	//float	kSpecular;


	Material();
	Material(LightIntensity _Ambient, LightIntensity _Diffuse, LightIntensity _Specular, float _SpecPower);
	~Material();
};

