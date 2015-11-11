#pragma once

#include "Math.h"
#include "Scene.h"
#include "Picture.h"

class CameraOrto
{
public:

	Vector	position;
	Vector	direction;
	float	scale;

	CameraOrto();
	CameraOrto(Vector Position, Vector Direction, float Scale = 1);
	~CameraOrto();

	void	Render	(Scene scene, Picture& picture);
	void	RenderAndPrint	(Scene scene, Picture& picture, char* filename);

	Vector2	GetPXWorldCenter(int x, int y, float pxWidth, float pxHeight);

};

