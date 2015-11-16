#include "PointLight.h"


PointLight::PointLight()
{
}

PointLight::PointLight(Vector _Position, LightIntensity _Light, float _Intensity) : position(_Position), color(_Light), intensity(_Intensity)
{

}


PointLight::~PointLight()
{
}
