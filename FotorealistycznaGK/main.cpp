#include <iostream>
#include <conio.h>
#include <chrono>

#include "Shapes.h"
#include "Zadania.h"

using namespace std;

//#define _SCL_SECURE_NO_WARNINGS

int main()
{
	auto start = chrono::steady_clock::now();
	

	Zadania z = Zadania();
	z.RunZad4();

	//Vector v = Vector(1, 1, 1);
	//
	//v.PrintNL();
	//v = -v;
	////printf("%f, %f, %f\n", v.x, v.y, v.z);
	//v.PrintNL();
	//
	//v = 5.0f * v;
	//v = 2 * v;
	//v.PrintNL();
	//
	//printf("%f\n", v.Length());
	//
	//v.NormalizeProduct().PrintNL();
	//printf("%f\n", v.Length());
	//
	//Ray r = Ray(Vector(-10,0,0), Vector(1,0,0));
	//
	//Sphere s = Sphere(Vector(0), 1);
	//float distance = 1000;
	//int intersect = s.Intersect(r, distance);
	//
	//printf("Intersected : %i on distance %f\n", intersect, distance);
	//
	//Plane plane = Plane(Vector(2), Vector(-1, 0, 0), 2);
	//Vector	planeIntersect;
	//int ifIntersected = plane.Intersect(r, planeIntersect);
	//printf("%i\n", ifIntersected);
	//planeIntersect.PrintNL();
	//
	//cout << "Dzia³a";


	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "\n\n\n" << chrono::duration <double, ratio<1,1>>(diff).count() << " sec  ==  " << chrono::duration <double, milli>(diff).count() << " ms  ==  " << chrono::duration <double, nano>(diff).count() << " ns" << endl;
	_getch();

	return 0;
}