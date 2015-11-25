#include "Zadania.h"
#include <cstdio>
//#include <string>

using namespace std;

void	Zadania::RunZad1()
{
	//Z1 - implementacja - DONE

	//Z2
	Sphere S = Sphere(Vector(0), 10);

	//Z3
	Ray	R1 = Ray(Vector(0, 0, -20), (S.center - Vector(0, 0, -20)).NormalizeProduct());

	//Z4
	Ray	R2 = Ray(Vector(0, 0, -20), 1000000, Vector(0, 1, 0));

	//Z5
	Vector r1Intersect1 = Vector();
	Vector r1Intersect2 = Vector();
	float distance = 1000000.0f;
	int results = S.Intersect(R1, distance, r1Intersect1, r1Intersect2);
	printf("R1 Sphere ## Intersection : %i\n", results);
	if (results > 0)
	{
		r1Intersect1.PrintNL();
		if (results > 1)
		{
			r1Intersect2.PrintNL();
		}
	}

	results = S.Intersect(R2, distance, r1Intersect1, r1Intersect2);
	printf("R2 Sphere ## Intersection : %i\n", results);
	if (results > 0)
	{
		r1Intersect1.PrintNL();
		if (results > 1)
		{
			r1Intersect2.PrintNL();
		}
	}

	//Z6
	Ray	R3 = Ray(Vector(0, 0, 0), Vector(0, 1, 0));
	results = S.Intersect(R3, distance, r1Intersect1, r1Intersect2);
	printf("\n\nR3 Sphere ## Intersection : %i\n", results);
	if (results > 0)
	{
		r1Intersect1.PrintNL();
		if (results > 1)
		{
			r1Intersect2.PrintNL();
		}
	}


	//Z7
	Plane P = Plane(Vector(0,1,1), Vector(0));
	Vector planeIntersection = Vector();
	float dist = 0;
	results = P.Intersect(R2, planeIntersection, dist);

	printf("\n\nPlane R2 ## Intersection : ");
	if (results == __HIT_ALLIGNED)
	{
		printf("ALLIGNED");
	}
	else if (results == __HIT_ONE)
	{
		planeIntersection.PrintNL();
	}
	else if (results == __HIT_MISS)
	{
		printf("MISSED");
	}

}

void	Zadania::RunZad2()
{
	//LightIntensity li = LightIntensity();

	Picture p = Picture(256, 256);
	//p.SetPixel(0, 0, LightIntensity(1, 0, 0));
	//p.SetPixel(0, 1, LightIntensity(0, 1, 0));
	//p.SetPixel(1, 0, LightIntensity(1, 0, 1));
	////p.SetPixel(3, 0, LightIntensity(1, 0, 0));
	////p.SetPixel(4, 0, LightIntensity(1, 0, 0));

	Scene scene = Scene();
	Sphere sp1 = Sphere(Vector(0, 0, 100), 2.0f, LightIntensity(0.5f));
	Sphere sp2 = Sphere(Vector(2, 0, 102.0f), 2.5f, LightIntensity(1.0f));
	Sphere sp3 = Sphere(Vector(-2, 0, 100.5f), 1.5f, LightIntensity(0.6f,0.1f,0));

	scene.Add(&sp1);
	scene.Add(&sp2);
	scene.Add(&sp3);

//	CameraOrto	camOrto = CameraOrto(Vector(0,0,-10), Vector(0,0,1), 2.0f);
//	camOrto.Render(scene, p);

//	CameraPerspective	camPersp = CameraPerspective(Vector(0,0,96), Vector(0,0,1), 3);
	//camPersp.Render(scene, p);

	p.PrintToFile("test.bmp");
}

void	Zadania::RunZad3()
{
	OBJParser objparser = OBJParser();

	Scene scene = Scene();
	vector<Mesh> meshes = vector<Mesh>();
	Sphere	sp = Sphere(Vector(-100,-1000,200), 1000000, LightIntensity(0,0.6f,0));
	Plane	pln = Plane(Vector(0,0, -1), -100, LightIntensity(0,0.3f, 1));
	CameraPerspective camPersp = CameraPerspective(Vector(40, -4,-30), Vector(-0.5f,0,0.5f), 100000000000, 1, 1);
	//CameraOrto	camOrto = CameraOrto(Vector(0,0,-20), Vector(0,0,1), 10.1f);
	Picture picture = Picture(64,64);

	objparser.Parse("ladnyDomek.obj", scene);
	//scene.objs.pop_back();
	//scene.objs.pop_back();
	//scene.objs.pop_back();
	//scene.objs.pop_back();

	//scene.objs.erase(scene.objs.begin());

	//printf("Meshes number %i\n", meshes.size());
	scene.Add(&sp);
	scene.Add(&pln);

	//scene.Add(meshes);

	//Triangle t0 = Triangle(Vector(-4, -2, 1), Vector(3, -1, 1), Vector(0, 6, 1), Vector(0, 0, 1));
	//t0.color = LightIntensity(0, 0, 1);
	//Triangle t1 = Triangle(Vector(0, 6, 1), Vector(3, -1, 1), Vector(5, 6, 1), Vector(0, 0, 1));
	//t1.color = LightIntensity(1, 0, 0);
	////scene.Add(&t0);
	////scene.Add(&t1);

	//Mesh m0 = Mesh(LightIntensity(0,1,0));
	//m0.triangles.push_back(new Triangle(t0));
	//m0.triangles.push_back(new Triangle(t1));
	//
	//scene.Add(&m0);

	//camOrto.Render(scene, picture);
	camPersp.Render(scene, picture);
	picture.PrintToFile("zad3.bmp");

///	Ray r1 = Ray(Vector(0,0, -10), 10000000, Vector(0,0,1));
///	float dist1 = -1;
///	int result = t0.IntersectDistance(r1, dist1);
///	dist1 = dist1;

//	Ray r0 = Ray(Vector(10,10,0), 100000, Vector(0, 0, 1));
//	float dist0 = -1;
//	if (scene.objs[0]->IntersectDistance(r0, dist0) == __HIT_ONE)
//	{
//		printf("\n\nIntersedted : distance = %f", dist0);
//	}



	//Ray r0 = Ray(Vector(0), 100000, Vector(0,0,1));
	//Triangle t0 = Triangle(Vector(-1,-1, 1), Vector(1, -1, 1), Vector(0, 1, 1));
	//float dist0 = -1;
	//if (t0.IntersectDistance(r0, dist0) == __HIT_ONE)
	//{
	//	printf("\n\nIntersedted : distance = %f", dist0);
	//}

}

void	Zadania::RunZad4()
{
	Scene scene = Scene();
	Sphere	sp = Sphere(Vector(0, 0, 0), 1, LightIntensity(0.1f, 0.1f, 0.1f));
	CameraPerspective camPersp = CameraPerspective(Vector(0, 0, -1.5f), Vector(0, 0, 1), 100000000000, 1, 1);
	//CameraOrto	camOrto = CameraOrto(Vector(0,0,-20), Vector(0,0,1), 10.1f);
	Picture picture = Picture(64, 64);

	PointLight	light1 = PointLight(Vector(0, 1000.2f , 1000), LightIntensity(1,1,1), 10 );
	PointLight	light2 = PointLight(Vector(1000, -1000, -200), LightIntensity(1, 0,	0), 100);

	scene.Add(&sp);
	scene.Add(&light1);
	scene.Add(&light2);

	camPersp.Render(scene, picture);
	picture.PrintToFile("zad4.bmp");

}

void	Zadania::RunZad5()
{
	int size = 64;
	Picture texture = Picture(size, size);
	int	tempI = 0, tempJ = 0;
	int divider = size / 16;
	for (int i = 0; i < size; i++)
	{
		tempI = i / divider;
		for (int j = 0; j < size; j++)
		{
			tempJ = (j / divider + tempI) % 16;
			texture.SetPixel(i, j, LightIntensity::GetColorM16(tempJ));
		}
	}

	texture.PrintToFile("z5Tex.bmp");

	// ###############

	Scene scene = Scene();
	Sphere	sp = Sphere(Vector(0, 0, 0), 1, LightIntensity(0.1f, 0.1f, 0.1f));
	CameraPerspective camPersp = CameraPerspective(Vector(0, 0, -1.5f), Vector(0, 0, 1), 100000000000, 1, 1);
	//CameraOrto	camOrto = CameraOrto(Vector(0,0,-20), Vector(0,0,1), 10.1f);
	Picture picture = Picture(64, 64);

	Triangle	t1 = Triangle(Vector(-1,0,0), Vector(1, 0, 0), Vector(0, 1, 0), Vector(0,0,1), LightIntensity::GetColorM16(2), Vector2(0, 0), Vector2(1000, 0), Vector2(500.0f, 1000));

	scene.tempMaterial.texture = &texture;
	scene.tempMaterial.texSize = size;

	PointLight	light1 = PointLight(Vector(0, 1000.2f, 1000), LightIntensity(1, 1, 1), 10);

	scene.Add(&sp);
	//scene.Add(&t1);
	scene.Add(&light1);

	camPersp.Render(scene, picture);
	picture.PrintToFile("zad5.bmp");

}

void	Zadania::RunZad6()
{

	Scene scene = Scene();
	CameraPerspective camPersp = CameraPerspective(Vector(0, -2.5f, -2.5f), Vector(0, 0, 1), 100000000000, 1, 1, 0);
	Picture picture = Picture(128, 128);

	PointLight	light1 = PointLight(Vector(0, 4, 0), LightIntensity(1, 1, 1), 9);
	Material	material1 = Material(LightIntensity(0.3f, 0.3f, 0.3f), LightIntensity(0.5f, 0.5f, 0.5f), LightIntensity(0.0f, 1.0f, 0.9f), 32, MaterialType::Refractive	);
	Material	material2 = Material(LightIntensity(0.3f, 0.3f, 0.3f), LightIntensity(0.5f, 0.5f, 0.5f), LightIntensity(1.0f, 1.0f, 0.9f), 32, MaterialType::Diffuse);
	Material	material3 = Material(LightIntensity(0.3f, 0.3f, 0.3f), LightIntensity(0.5f, 0.0f, 0.5f), LightIntensity(1.0f, 1.0f, 0.9f), 10, MaterialType::Diffuse);
	Material	materialRed = Material(LightIntensity(0.3f, 0, 0), LightIntensity(0.5f, 0, 0), LightIntensity(1.0f, 0, 0), 10, MaterialType::Diffuse);
	Material	materialBlue = Material(LightIntensity(0, 0, 0.3f), LightIntensity(0, 0, 0.5f), LightIntensity(0, 0, 1), 10, MaterialType::Diffuse);
	Material	materialBlack = Material(LightIntensity(0, 0, 0), LightIntensity(0, 0, 0), LightIntensity(0, 0, 0), 10, MaterialType::Diffuse);
	Material	materialCeiling = Material(LightIntensity(.6f, 0.6f, 0.6f), LightIntensity(0, 0, 0), LightIntensity(0, 0, 0), 10, MaterialType::Haxative);
	Material	materialRefl = Material(LightIntensity(0.3f, 0.3f, 0.3f), LightIntensity(0.5f, 0.5f, 0.5f), LightIntensity(0.0f, 1.0f, 0.9f), 32, MaterialType::Reflective);

	Sphere	sp	= Sphere(Vector(0, 0, 0), 0.2f, LightIntensity(0.1f, 0.1f, 0.1f), 0);
	Sphere	sp1	= Sphere(Vector(1.2f, -2.8f, 0), .8f, LightIntensity(0.1f, 0.1f, 0.1f), 0);
	Sphere	sp2 = Sphere(Vector(-0.5f, -2.8f, 1), .8f, LightIntensity(0.1f, 0.1f, 0.1f), 5);
	Sphere	sp3 = Sphere(Vector(3, -1, 3.1f), 0.3f, LightIntensity(0.1f, 0.1f, 0.1f), 2);
	Sphere	sp4 = Sphere(Vector(0, -10004, 0), 100000000, LightIntensity(0.1f, 0.1f, 0.1f), 1);
	Sphere	sp5 = Sphere(Vector(0, 10004, 0), 100000000, LightIntensity(0.1f, 0.1f, 0.1f), 7);
	Sphere	sp6 = Sphere(Vector(-10004, 0, 0), 100000000, LightIntensity(0.1f, 0.1f, 0.1f), 3);
	Sphere	sp7 = Sphere(Vector(10004, 0, 0), 100000000, LightIntensity(0.1f, 0.1f, 0.1f), 4);
	Sphere	sp8 = Sphere(Vector(0, 0, 10004), 100000000, LightIntensity(0.1f, 0.1f, 0.1f), 1);
	Sphere	sp9 = Sphere(Vector(0, 0, -10008), 100000000, LightIntensity(0.1f, 0.1f, 0.1f), 6);

	//scene.Add(&sp);
	scene.Add(&sp1);
	scene.Add(&sp2);
	scene.Add(&sp3);
	scene.Add(&sp4);
	scene.Add(&sp5);
	scene.Add(&sp6);
	scene.Add(&sp7);
	scene.Add(&sp8);
	scene.Add(&sp9);
	scene.Add(&light1);
	scene.Add(&material1);
	scene.Add(&material2);
	scene.Add(&material3);
	scene.Add(&materialRed);
	scene.Add(&materialBlue);
	scene.Add(&materialRefl);
	scene.Add(&materialBlack);
	scene.Add(&materialCeiling);


	Vector	tempMath = Vector(0);
	float	tempFloat = 0;
	int		tempInt = 0;
	sp.IntersectWithBackfaces(Ray(Vector(0, 0, 0.1f), 1000000, Vector(0, 0, 1)), tempMath);
	tempInt = sp.IntersectDistance(Ray(Vector(0, 0, 0), 1000000, Vector(0, 0, 1)), tempFloat);
	tempMath.PrintNL();
	printf("dist : %f with hits %i", tempFloat, tempInt);


	camPersp.Render(scene, picture);
	picture.PrintToFile("zad6.bmp");



}