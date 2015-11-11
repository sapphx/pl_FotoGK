#include "CameraOrto.h"


CameraOrto::CameraOrto() : position(Vector(0)), direction(Vector(0,0,1)), scale(1)
{
}

CameraOrto::CameraOrto(Vector Position, Vector Direction, float Scale) : position(Position), direction(Direction), scale(Scale) {}

CameraOrto::~CameraOrto()
{
}


void	CameraOrto::Render(Scene scene, Picture& picture)
{
	float	pxWidth = 2.0f / picture.size.x;
	float	pxHeight = 2.0f / picture.size.y;

	Vector2	pxCenter;
	int		sceneObjCount = scene.objs.size();

	const	float	initialDistance = 10000000000;
	float	minDistance = initialDistance;
	float	distance = 0;

	int		temp = 0;

	//Vector2	center = Vector2(-1.0f + (x + 0.5f) * szerokoscPixela)

	for (int i = 0; i < picture.size.x; i++)
	{
		for (int j = 0; j < picture.size.y; j++)
		{
			minDistance = initialDistance;
			pxCenter = GetPXWorldCenter(i, j, pxWidth, pxHeight) * scale;
			//HERE TO CHANGE IN CASE OF ROTATION NEEDED
			Ray ray = Ray(Vector(pxCenter.x, pxCenter.y, 0), Vector(0, 0, 1));
			////////Ray ray = Ray(Vector(0, 0, 0), Vector(0, 0, 1));
			
			for (int l = 0; l < sceneObjCount; l++)
			{
				distance = initialDistance;
				temp = scene.objs[l]->IntersectDistance(ray, distance);

				if ( temp > 0)
				{
					if (distance < minDistance)
					{
						minDistance = distance;
						picture.SetPixel(i, j, scene.objs[l]->GetColor());
					}
				}
				
			}

			if (minDistance == initialDistance)
			{
				picture.SetPixel(i, j, LightIntensity(0));
			}

		}
	}

}


Vector2	CameraOrto::GetPXWorldCenter(int x, int y, float pxWidth, float pxHeight)
{
	return Vector2(-1.0f + (float)(x + 0.5f) * pxWidth, 1.0f - (float)(y + 0.5f) * pxHeight);
}