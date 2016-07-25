#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Image.h"
#include "Vector3.h"
#include "Color.h"
#include "Shape.h"
#include "Sphere.h"
#include "ShadeRec.h"

#include "RayTracer.h"



int main(int argc, char *argv[])
{
	const int width = 640;
	const int height = 480;

	RayTracer raytracer(width, height, "WriteImage.ppm");

	raytracer.addShape(new Sphere(Vector3(300, 300, -100), 100, Color(1.0, 0.4, 0.0)));

	for (int Y = 0; Y < height; ++Y)
	{
		for (int X = 0; X < width; ++X)
		{
			Ray camRay = raytracer.castRay(X, Y);
			Color pixcolor = raytracer.traceRay(camRay);
			raytracer.image->pixel(X, Y, pixcolor);
		}
	}

/*
	Color color;
	ShadeRec rec;
	for (int Y = 0; Y < height; ++Y)
	{
		for (int X = 0; X < width; ++X)
		{
			Vector3 origin(double(X), double(Y), 0.0);
			Vector3 direction(0, 0, -1.0);
			Ray camRay(origin, direction);
			rec = sphere.hit(camRay);
			if (rec.hit)
				color = rec.color;
			else
				color = Color(0);
			image.pixel(X, Y, color);
		}
	}

	image.WritePPM("WriteImage.ppm");

	RayTracer raytracer(width, height);
	*/
	raytracer.write();

	return 0;
}
