#pragma once
class LightIntensity
{
public:
	float r, g, b;
	
	LightIntensity();
	LightIntensity(float	R, float	G, float	B);
	LightIntensity(float	all);
	~LightIntensity();

	////OPERATORS

	void operator()(float R, float G, float B);

	LightIntensity	operator+(LightIntensity &li);
	LightIntensity	operator-(LightIntensity &li);
	LightIntensity	operator/(float num);
	LightIntensity	operator*(LightIntensity &li);

	LightIntensity	operator+=(LightIntensity &li);
	LightIntensity	operator-=(LightIntensity &li);
	LightIntensity	operator*=(float num);
	LightIntensity	operator/=(float num);

	friend LightIntensity	operator*(float num, LightIntensity &li);
	friend LightIntensity	operator*(LightIntensity &li, float num);
//	friend std::ostream&	operator<<(std::ostream& str, LightIntensity &li);

	////FUNCTIONS

	void	Add(double R, double G, double B);

	void	Print();
	void	PrintNL();

	__forceinline	void	ClampColors() { if (r > 1) r = 1; if (g > 1) g = 1; if (b > 1) b = 1;}

	static	LightIntensity	GetColorM16(int iter);

	__forceinline	bool	TestProbleCornerWithCenter(LightIntensity corner, float difference) 
	{ 
		if	(	(r - corner.r < difference || corner.r - r < difference) &&
				(g - corner.g < difference || corner.g - g < difference) &&
				(b - corner.b < difference || corner.b - b < difference)	)
		{
			return true;
		}
		return false;
	}

	__forceinline	bool	TestProbleCornerWithCenter(LightIntensity center, LightIntensity corner, float difference)
	{
		if ((center.r - corner.r < difference || corner.r - center.r < difference) &&
			(center.g - corner.g < difference || corner.g - center.g < difference) &&
			(center.b - corner.b < difference || corner.b - center.b < difference))
		{
			return true;
		}
		return false;
	}

};

