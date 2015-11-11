#pragma once

#include <string>

#pragma warning(disable:4996)
#define _SCL_SECURE_NO_WARNINGS

#include "LightIntensity.h"
#include "Vector2.h"
//#include "bitmap_image.hpp"

class Picture
{
public:
	
	LightIntensity	**image;
	Vector2			size;

	Picture();
	Picture(int sizeX, int sizeY);
	~Picture();

	void	PrintToFile(char*  filename);

	void			SetPixel(int sx, int sy, LightIntensity li);
	LightIntensity	GetPixel(int sx, int sy);
};

