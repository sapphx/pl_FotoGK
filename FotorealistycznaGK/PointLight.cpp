#include "PointLight.h"


PointLight::PointLight()
{
}

PointLight::PointLight(Vector _Position, LightIntensity _Light) : position(_Position), color(_Light)
{

}


PointLight::~PointLight()
{
}
