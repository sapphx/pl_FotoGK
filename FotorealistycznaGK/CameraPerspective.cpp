#include "CameraPerspective.h"


CameraPerspective::CameraPerspective()
{
	position = Vector(0, 0, 0);
	target = Vector(0, 0, 1);
	nearPlane = 1;
	farPlane = 1000;
	up = Vector(0, 1, 0);
	fov = 1;
	compute_uwv();
}

CameraPerspective::CameraPerspective(Vector Position, Vector Target, float FarPlane, float NearPlane, int AaIterations)
{
	position = Position;
	target = Target.NormalizeProduct();
	nearPlane = NearPlane;
	farPlane = FarPlane;
	up = Vector(0, 1, 0);
	fov = 1;
	aaIterations = AaIterations;
	compute_uwv();
}

CameraPerspective::~CameraPerspective()
{
}


__forceinline	void	CameraPerspective::compute_uwv()
{
	//I SUPPOSE TARGET IS NORMALIZED - it should be, unless You really want it will be 
	w = -target;
	u = -up.Cross(w);
	v = w.Cross(u);
}


void	CameraPerspective::Render(Scene& scene, Picture& picture)
{
	float	pxWidth = 2.0f / picture.size.x;
	float	pxHeight = 2.0f / picture.size.y;

	Vector2	pxCenter;
	int		sceneObjCount = scene.objs.size();
	const	float	initialDistance = farPlane;// - nearPlane;
	float	minDistance = initialDistance;

	float	distance = 0;
	int		temp = 0;

	Vector	viewPlane = position + target * fov;
	Vector	pointOnPlane;

	for (int i = 0; i < picture.size.x; i++)
	{
		for (int j = 0; j < picture.size.y; j++)
		{
			minDistance = initialDistance;
			pxCenter = GetPXWorldCenter(i, j, pxWidth, pxHeight);

			pointOnPlane = viewPlane + u * pxCenter.x + v * pxCenter.y;
		//	Ray ray = Ray(pointOnPlane, initialDistance, pointOnPlane - position);
		//
		//	for (int l = 0; l < sceneObjCount; l++)
		//	{
		//		distance = initialDistance;
		//		temp = scene.objs[l]->IntersectDistance(ray, distance);
		//
		//		if (temp > 0)
		//		{
		//			if (distance < minDistance)
		//			{
		//				minDistance = distance;
		//				picture.SetPixel(i, j, scene.objs[l]->GetColor());
		//			}
		//		}
		//
		//	}
		

			picture.SetPixel(i, j, AAProbing(scene, pointOnPlane, initialDistance, pxWidth, pxHeight, aaIterations, 0.05f));

			//if (minDistance == initialDistance)
			//{
			//	picture.SetPixel(i, j, LightIntensity(0));
			//}

		}
	}

}

__forceinline Vector2	CameraPerspective::GetPXWorldCenter(int x, int y, float pxWidth, float pxHeight)
{
	return Vector2(-1.0f + (float)(x + 0.5f) * pxWidth, 1.0f - (float)(y + 0.5f) * pxHeight);
}


LightIntensity	CameraPerspective::AAProbing(Scene& scene, Vector pointOnPlane, float initialDistance, float pixelWidth, float pixelHeight, int iterationsLeft, float difference, EProbes phase, LightIntensity corner1v2, LightIntensity corner3v4)
{
	int iterLeft = iterationsLeft - 1;

	const	float	iDistance = initialDistance;
	LightIntensity	center = LightIntensity();
	LightIntensity	corner1 = LightIntensity();
	LightIntensity	corner2 = LightIntensity();
	LightIntensity	corner3 = LightIntensity();
	LightIntensity	corner4 = LightIntensity();

	float halfWidth = pixelWidth * 0.5f;
	float halfHeight = pixelHeight * 0.5f;

	Vector	tempVector = Vector();

	center = TestWithAllObjectsInScene(scene, Ray(pointOnPlane, initialDistance, pointOnPlane - position), iDistance);

	if (phase == EProbes::Corner1n4)
	{
		corner1 = corner1v2;
		corner4 = corner3v4;
	}
	else
	{
		initialDistance = iDistance;
		tempVector = pointOnPlane - u * halfWidth - v * halfHeight;
		corner1 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);

		initialDistance = iDistance;
		tempVector = pointOnPlane + u * halfWidth + v * halfHeight;
		corner4 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	}

	if (phase == EProbes::Corner2n3)
	{
		corner2 = corner1v2;
		corner3 = corner3v4;
	}
	else
	{
		initialDistance = iDistance;
		tempVector = pointOnPlane + u * halfWidth - v * halfHeight;
		corner2 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);

		initialDistance = iDistance;
		tempVector = pointOnPlane - u * halfWidth + v * halfHeight;
		corner3 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	}

	//switch (phase)
	//{
	//case Start:
	//
	//	initialDistance = iDistance;
	//	tempVector = pointOnPlane - u * halfWidth - v * halfHeight;
	//	corner1 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	//
	//	initialDistance = iDistance;
	//	tempVector = pointOnPlane + u * halfWidth - v * halfHeight;
	//	corner2 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	//
	//	initialDistance = iDistance;
	//	tempVector = pointOnPlane - u * halfWidth + v * halfHeight;
	//	corner3 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	//
	//	initialDistance = iDistance;
	//	tempVector = pointOnPlane + u * halfWidth + v * halfHeight;
	//	corner4 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	//
	//	break;
	//case Corner1n4:
	//	
	//	corner1 = corner1v2;
	//	corner4 = corner3v4;
	//
	//	initialDistance = iDistance;
	//	tempVector = pointOnPlane + u * halfWidth - v * halfHeight;
	//	corner2 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	//
	//	initialDistance = iDistance;
	//	tempVector = pointOnPlane - u * halfWidth + v * halfHeight;
	//	corner3 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	//
	//	break;
	//case Corner2n3:
	//
	//	corner2 = corner1v2;
	//	corner3 = corner3v4;
	//
	//	initialDistance = iDistance;
	//	tempVector = pointOnPlane - u * halfWidth - v * halfHeight;
	//	corner1 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	//
	//	initialDistance = iDistance;
	//	tempVector = pointOnPlane + u * halfWidth + v * halfHeight;
	//	corner4 = TestWithAllObjectsInScene(scene, Ray(tempVector, initialDistance, tempVector - position), iDistance);
	//
	//	break;
	//default:
	//	break;
	//}

	halfWidth *= 0.5f;
	halfHeight *= 0.5f;

	if (iterLeft > 0)
	{
		if (center.TestProbleCornerWithCenter(corner1, difference) == false)
		{
			tempVector = pointOnPlane - u * halfWidth - v * halfHeight;
			corner1 = AAProbing(scene, tempVector, iDistance, halfWidth, halfHeight, iterLeft, difference, EProbes::Corner1n4, corner1, center);
		}

		if (center.TestProbleCornerWithCenter(corner2, difference) == false)
		{
			tempVector = pointOnPlane + u * halfWidth - v * halfHeight;
			corner2 = AAProbing(scene, tempVector, iDistance, halfWidth, halfHeight, iterLeft, difference, EProbes::Corner2n3, corner2, center);
		}

		if (center.TestProbleCornerWithCenter(corner3, difference) == false)
		{
			tempVector = pointOnPlane - u * halfWidth + v * halfHeight;
			corner3 = AAProbing(scene, tempVector, iDistance, halfWidth, halfHeight, iterLeft, difference, EProbes::Corner2n3, center, corner3);
		}

		if (center.TestProbleCornerWithCenter(corner4, difference) == false)
		{
			tempVector = pointOnPlane + u * halfWidth + v * halfHeight;
			corner4 = AAProbing(scene, tempVector, iDistance, halfWidth, halfHeight, iterLeft, difference, EProbes::Corner1n4, center, corner4);
		}
	}

	return (center + corner1 + corner2 + corner3 + corner4) * 0.2f;
}


LightIntensity	CameraPerspective::TestWithAllObjectsInScene(Scene& scene, Ray ray, float initialDistance)
{
	LightIntensity tempColor = LightIntensity(0);
	float distance;
	float temp = initialDistance;

	int		impactedIter = -1;

	for (int l = 0; l < scene.objs.size(); l++)
	{
		distance = initialDistance;

		if (scene.objs[l]->IntersectDistance(ray, distance) > 0)
		{
			if (distance < temp)
			{
				temp = distance;
				tempColor = scene.objs[l]->innerColor;
				impactedIter = l;
			}
		}
	}

	if (temp < initialDistance)
	{
		Vector	impactPos = temp * ray.direction + ray.origin;
		float	NdotL = 0;
		for (int k = 0; k < scene.lights.size(); k++)
		{
			Ray lightRay = Ray(impactPos, scene.lights[k]->position);
			
			for (int l = 0; l < scene.objs.size(); l++)
			{
				if (l == impactedIter)
				{
					NdotL = lightRay.direction.Dot(scene.objs[l]->GetNormal(lightRay.origin));
					if (NdotL < 0) NdotL = 0;
					tempColor = tempColor * scene.lights[k]->color * NdotL;//LightIntensity(0.5f, 0, 0);//temp * scene.lights[k]->color;
					continue;
				}
				
				distance = initialDistance;

				if (scene.objs[l]->IntersectDistance(lightRay, distance) == 0)
				{
					tempColor = tempColor * scene.lights[k]->color;
				}
			}
		}
	}

	return tempColor;
}

