#pragma once

#include <vector>
#include "Shapes.h"
#include "Mesh.h"
#include "PointLight.h"

class Scene
{
public:

	std::vector<Shape*> objs;
	std::vector<PointLight*> lights;

	Scene();
	~Scene();

	void	Add(Shape* s);
	void	Add(std::vector<Mesh> meshes);

	void	Add(PointLight* l);

};

