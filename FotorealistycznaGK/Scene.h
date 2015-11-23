#pragma once

#include <vector>
#include "Shapes.h"
#include "Mesh.h"
#include "PointLight.h"
#include "Material.h"

class Scene
{
public:

	std::vector<Shape*> objs;
	std::vector<PointLight*> lights;
	std::vector<Material*> materials;

	Material	tempMaterial;

	Scene();
	~Scene();

	void	Add(Shape* s);
	void	Add(std::vector<Mesh> meshes);

	void	Add(PointLight* l);
	void	Add(Material* mat);
};

