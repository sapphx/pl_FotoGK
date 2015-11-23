#include "Material.h"



Material::Material()
{
}

Material::Material(LightIntensity _Ambient, LightIntensity _Diffuse, LightIntensity _Specular, float _SpecPower, MaterialType _MaterialType) : ambient(_Ambient), diffuse(_Diffuse), specular(_Specular), specularPower(_SpecPower), materialType(_MaterialType)
{
	//SetTexture();
}


Material::~Material()
{
}


void	Material::SetTexture()
{
	//int size = 64;
	//texSize = size;
	//texture = Picture(size, size);
	//int	tempI = 0, tempJ = 0;
	//int divider = size / 16;
	//for (int i = 0; i < size; i++)
	//{
	//	tempI = i / divider;
	//	for (int j = 0; j < size; j++)
	//	{
	//		tempJ = (j / divider + tempI) % 16;
	//		texture.SetPixel(i, j, LightIntensity::GetColorM16(tempJ));
	//	}
	//}
}