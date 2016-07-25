#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Constants.h"

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

	RayTracer raytracer(width, height, "WriteImage3.ppm");

	raytracer.addShape(new Sphere(Vector3(200, 150, -300), 80, Color(1.0, 1.0, 0.0)));
	raytracer.addShape(new Sphere(Vector3(300, 150, -300), 80, Color(1.0, 0.0, 0.0)));
	raytracer.addShape(new Sphere(Vector3(320, 240, -400), 100, Color(1.0, 0.4, 0.0)));
	raytracer.addShape(new Sphere(Vector3(320, 2480, -400), 2130, Color(0.5, 0.4, 0.5)));

	raytracer.addLight(new Light(Vector3(0, -100, -300)));
	raytracer.addLight(new Light(Vector3(640, -100, -300)));


	Color pixcolor(0);
	ShadeRec rec;
	for (int Y = 0; Y < height; ++Y)
	{
		for (int X = 0; X < width; ++X)
		{
			pixcolor = Color(0);

			Ray camRay = raytracer.castRay(X, Y);
			rec = raytracer.traceRay(camRay);
			if (rec.hit)
			{
				pixcolor = raytracer.calculate_pixel_color(rec);
			}
			raytracer.image->pixel(X, Y, pixcolor);
		}
	}

	//raytracer.image->clamp(1.0);

	raytracer.write();

	return 0;
}
