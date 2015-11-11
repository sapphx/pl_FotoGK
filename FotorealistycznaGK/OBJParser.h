#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include <cstdio>

#include "Triangle.h"
#include "Mesh.h"
#include "Scene.h"


using namespace std;

class OBJParser
{
public:
	vector<Triangle> list;
	
	OBJParser();
	~OBJParser();

	void	Parse(char* filename, Scene& scene);//vector<Mesh>& meshes);

};

