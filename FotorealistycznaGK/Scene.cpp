#include "Scene.h"


Scene::Scene()
{
	objs = std::vector<Shape*>();
	lights = std::vector<PointLight*>();
	tempMaterial = Material(LightIntensity(0.4f, 0.4f, 0.4f), LightIntensity(0.7f, 0.7f, 0.7f), LightIntensity(0.9f, 1.0f, 0.9f), 32, MaterialType::Diffuse );
}


Scene::~Scene()
{
	//for (int i = 0; i < objs.size(); i++)
	//{
	//	delete objs[i];
	//}
	objs.clear();
}

void	Scene::Add(Shape* s) 
{ 
	objs.push_back(s); 
}

void	Scene::Add(std::vector<Mesh> meshes)
{
	for (int i = 0; i < meshes.size(); i++)
	{
		objs.push_back(&meshes[i]);
	}
}

void	Scene::Add(PointLight* l)
{
	lights.push_back(l);
}

void Scene::Add(Material * mat)
{
	materials.push_back(mat);
}
