#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Image.h"
#include "Vector3.h"
#include "Color.h"
#include "Shape.h"
#include "Sphere.h"



int main(int argc, char *argv[])
{
	const int width = 640;
	const int height = 480;

	Image image(width, height);

	Sphere sphere(Vector3(200, 200, -100), 100);


	Color color;
	for (int Y = 0; Y < height; ++Y)
	{
		for (int X = 0; X < width; ++X)
		{
			Vector3 origin(double(X), double(Y), 0.0);
			Vector3 direction(0, 0, -1.0);
			Ray camRay(origin, direction);
			if (sphere.hit(camRay))
				color = Color(1.0);
			else
				color = Color(0);
			image.pixel(X, Y, color);
		}
	}

	image.WritePPM("WriteImage.ppm");

	return 0;
}
