#pragma once
#pragma once

#include "LightIntensity.h"
#include "Picture.h"

enum MaterialType
{
	Diffuse = 0,
	Reflective,
	Refractive,
	Haxative
};

class Material
{
public:
	LightIntensity	ambient;
	LightIntensity	diffuse;
	LightIntensity	specular;
	int				specularPower;
	MaterialType	materialType;
	//float	kDiffuse;
	//float	kSpecular;

	Picture*		texture;
	int				texSize;

	Material();
	Material(LightIntensity _Ambient, LightIntensity _Diffuse, LightIntensity _Specular, float _SpecPower, MaterialType _MaterialType);
	~Material();

	void	SetTexture();
};

