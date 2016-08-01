#include "Image.h"

//Image Constructor
Image::Image()
	:buffer(NULL), width(), height()
{}

Image::Image(int width_, int height_)
	:width(width_), height(height_)
{
	buffer = (Color *)malloc(width * height * sizeof(Color));
	Clear(Color(0.0));
}

//Image Destructor
Image::~Image()
{
	free(buffer);
}

//Write to PPM file format
void Image::WritePPM(const char *outfile)
{
	FILE *file;
	file = fopen(outfile, "w");
	fprintf(file, "P3\n%i %i\n255\n", width, height);

	for (int Y = 0; Y < height; ++Y)
	{
		for (int X = 0; X < width; ++X)
		{
			Color temp = buffer[Y * width + X];
			temp = temp.clamp();
			/*
			if (temp.r > 1.0 || temp.b > 1.0 || temp.g > 1.0)
			{
				temp.r = 1.0; temp.b = 0.0; temp.g = 0.0;
			}
			*/

			unsigned char ir = unsigned char(temp.r * 255.99);
			unsigned char ig = unsigned char(temp.g * 255.99);
			unsigned char ib = unsigned char(temp.b * 255.99);
			fprintf(file, "%uc %uc %uc ", ir, ig, ib);
		}
	}
	fclose(file);
}

void Image::Clear(Color& color)
{
	for (int Y = 0; Y < height; ++Y)
	{
		for (int X = 0; X < width; ++X)
		{
			buffer[Y * width + X] = color;
		}
	}
}

void Image::clamp(double d)
{
	for (int Y = 0; Y < height; ++Y)
	{
		for (int X = 0; X < width; ++X)
		{
			buffer[Y * width + X].clamp();
		}
	}
}


//Get the Color in the buffer
Color Image::pixel(int x, int y)
{
	return buffer[width * y + x];
}

//Set the Color in the buffer
void Image::pixel(int x, int y, Color c)
{
	buffer[width * y + x] = c;
}
