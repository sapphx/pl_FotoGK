#pragma once

#include <vector>
#include "Shapes.h"
#include "Mesh.h"

class Scene
{
public:

	std::vector<Shape*> objs;

	Scene();
	~Scene();

	void	Add(Shape* s);
	void	Add(std::vector<Mesh> meshes);

};

