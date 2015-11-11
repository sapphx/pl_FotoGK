#include "Scene.h"


Scene::Scene()
{
	objs = std::vector<Shape*>();
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