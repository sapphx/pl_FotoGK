#include "OBJParser.h"

OBJParser::OBJParser()
{
}


OBJParser::~OBJParser()
{
}


void	OBJParser::Parse(char* filename, Scene& scene)//vector<Mesh>& meshes)
{
	ifstream	file;
	file.open(filename);

	if (!file.is_open())
		return;

	string	line;
	int i = 0;
	int v = 0;
	int g = -1; // Very important
	int f = 0;
	
	vector<Vector> vertices = vector<Vector>();
	vector<Vector> normals = vector<Vector>();
	vector<Triangle*> triangles = vector<Triangle*>();
	//vector<Mesh> meshes = vector<Mesh>();


	vector<string> tempHolder;
//	char * cLine;
//	char * p;
//	char* context = NULL;
	//char * cstr; = new char[str.length() + 1];
	string a;
	float	b, c, d;
	int		ia, ib, ic, in;
	char	t;

	Mesh*	meshPointer;

#pragma warning( push )
#pragma warning( disable : 4996 6386 )

	while (!file.eof()){
		getline(file, line);
		
		std::istringstream iss(line);
		iss >> a;
		switch (line[0])
		{
		case 'v' :
			v++;
			if (!(iss >> b >> c >> d)) { break; }

			switch (line[1])
			{
			case ' ':
				vertices.push_back(Vector(b,c,d));
				break;
			case 'n':
				normals.push_back(Vector(b,c,d));
//				cout << a << " % " << b << " " << c << " " << d << "\n";
				break;
			case 't':
				//TODO
				break;
			}

			
			//cLine = new char[line.length() + 1];
			//strcpy(cLine, line.c_str());
			//
			//p = strtok_s(cLine, " ", &context);
			//while (p != 0)
			//{
			//	cout << p << '\n';
			//	p = strtok_s(NULL, " ", &context);
			//}
			//cout << '\n';

			
			//string a, b, c, d;
			//delete[] cLine;
			break;
		case 'g':
			meshPointer = new Mesh(LightIntensity(0,1,0));
			scene.objs.push_back(meshPointer);
			g++;
			break;
		case 'f':
			if (g < 0) break;
			f++;
			iss >> ia >> t; 
			if (iss.peek() != '/')	
				iss >> in;
			iss >> t >> in >> ib >> t;
			if (iss.peek() != '/')	iss >> in;
			iss >> t >> in >> ic >> t;
			if (iss.peek() != '/')	iss >> in;
			iss >> t >> in ;
			//meshPointer->triangles.push_back(new Triangle(Vector(ia), Vector(ib), Vector(ic), Vector(in), LightIntensity::GetColorM16(f%16)));
			meshPointer->triangles.push_back(new Triangle(vertices[ia - 1], vertices[ib - 1], vertices[ic - 1], normals[in - 1], LightIntensity::GetColorM16(f % 16)));
			//scene.objs.push_back(new Triangle(Vector(vertices[ia]), Vector(vertices[ib]), Vector(vertices[ic]), Vector(normals[in]), LightIntensity::GetColorM16(f % 16)));
			break;
		}
		i++;
	}

#pragma warning( pop )

	printf("\n%i lines # v : %i  vn : %i  g : %i  f : %i\n", i, vertices.size(), normals.size(), g, triangles.size());
	vertices[0].PrintNL();
	printf("Triangles in mesh 1 : %i\n", meshPointer->triangles.size());


	file.close();
}