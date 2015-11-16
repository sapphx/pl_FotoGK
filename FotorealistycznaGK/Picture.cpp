#include "Picture.h"

#include <fstream>
#include <windows.h>

Picture::Picture()
{
}


Picture::Picture(int sizeX, int sizeY) : size(Vector2(sizeX, sizeY))
{
	image = new LightIntensity*[sizeX];
	for (int i = 0; i < sizeX; i++)
	{
		image[i] = new LightIntensity[sizeY];
		for (int j = 0; j < size.y; j++)
		{
			image[i][j] = LightIntensity(1);
		}
	}
}

Picture::~Picture()
{
	for (int i = 0; i < size.x; i++)
	{
		delete[] image[i];
	}
	delete[] image;
}


void	Picture::PrintToFile(char* filename)
{
	
	HANDLE file;
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER fileInfo;
	RGBTRIPLE *rgbImage;
 	DWORD write = 0;
	rgbImage = new RGBTRIPLE[(int)(size.x * size.y)];

	file = CreateFile(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	//Sets up the new bmp to be written to

	fileHeader.bfType = 19778;																			//Sets our type to BM or bmp
	fileHeader.bfSize = sizeof(fileHeader.bfOffBits) + sizeof(RGBTRIPLE);								//Sets the size equal to the size of the header struct
	fileHeader.bfReserved1 = 0;																			//sets the reserves to 0
	fileHeader.bfReserved2 = 0;
	fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);							//Sets offbits equal to the size of file and info header

	fileInfo.biSize = sizeof(BITMAPINFOHEADER);
	fileInfo.biWidth = size.x;
	fileInfo.biHeight = size.y;
	fileInfo.biPlanes = 1;
	fileInfo.biBitCount = 24;
	fileInfo.biCompression = BI_RGB;
	fileInfo.biSizeImage = 3 * size.x * size.y;
	fileInfo.biXPelsPerMeter = 2400;
	fileInfo.biYPelsPerMeter = 2400;
	fileInfo.biClrImportant = 0;
	fileInfo.biClrUsed = 0;

	WriteFile(file, &fileHeader, sizeof(fileHeader), &write, NULL);
	WriteFile(file, &fileInfo, sizeof(fileInfo), &write, NULL);

	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
		{
			int iterator = (i * size.x + j);
			rgbImage[iterator].rgbtBlue = (byte)(image[j][i].b * 255);
			rgbImage[iterator].rgbtGreen = (byte)(image[j][i].g * 255);
			rgbImage[iterator].rgbtRed = (byte)(image[j][i].r * 255);
		}
	}

	WriteFile(file, rgbImage, fileInfo.biSizeImage, &write, NULL);

	CloseHandle(file);

}


void	Picture::SetPixel(int sx, int sy, LightIntensity li)
{
	if (sx >= 0 && sy >= 0 && sx < size.x && sy < size.y)
	{
		li.ClampColors();
		image[sx][sy](li.r, li.g, li.b);
	}
}


LightIntensity	Picture::GetPixel(int sx, int sy)
{
	if (sx >= 0 && sy >= 0 && sx < size.x && sy < size.y)
	{
		return image[sx][sy];
	}
	return LightIntensity(0);
}