#include "Material.h"



Material::Material()
{
}

Material::Material(LightIntensity _Ambient, LightIntensity _Diffuse, LightIntensity _Specular, float _SpecPower) : ambient(_Ambient), diffuse(_Diffuse), specular(_Specular), specularPower(_SpecPower)
{
}


Material::~Material()
{
}
