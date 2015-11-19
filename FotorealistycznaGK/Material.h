#pragma once
#pragma once

#include "LightIntensity.h"
#include "Picture.h"

class Material
{
public:
	LightIntensity	ambient;
	LightIntensity	diffuse;
	LightIntensity	specular;
	int				specularPower;
	//float	kDiffuse;
	//float	kSpecular;
	
	Picture*		texture;
	int				texSize;

	Material();
	Material(LightIntensity _Ambient, LightIntensity _Diffuse, LightIntensity _Specular, float _SpecPower);
	~Material();

	void	SetTexture();
};

