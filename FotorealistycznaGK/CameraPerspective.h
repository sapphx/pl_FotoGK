#pragma once

#include <math.h>

#include "Math.h"
#include "Scene.h"
#include "Picture.h"

enum EProbes
{
	Start = 0,
	Corner1n4,
	Corner2n3
};

class CameraPerspective
{
public:
	Vector	position;
	Vector	target;
	Vector	up;

	Vector	v, u, w;

	float	nearPlane;
	float	farPlane;
	float	fov;

	int		aaIterations;
	
	CameraPerspective();
	CameraPerspective(Vector Position, Vector Target, float FarPlane = 1000, float NearPlane = 1, int AaIterations = 0);
	~CameraPerspective();

	__forceinline	void	compute_uwv();
	__forceinline	Vector2	GetPXWorldCenter(int x, int y, float pxWidth, float pxHeight);
	void	Render(Scene& scene, Picture& picture);

	LightIntensity	AAProbing(Scene& scene, Vector pointOnPlane, float initialDistance, float pixelWidth, float pixelHeight, int iterationsLeft, float difference, EProbes phase = EProbes::Start, LightIntensity corner1v2 = LightIntensity(0), LightIntensity corner3v4 = LightIntensity(0));
	LightIntensity	TestWithAllObjectsInScene(Scene& scene, Ray ray, float initialDistance);

	

};

