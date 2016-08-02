#include <stdio.h>
#include <stdlib.h>

#include "Constants.h"
#include "MathLib.h"

#include "Image.h"
#include "Vector3.h"
#include "Color.h"
#include "Shape.h"
#include "Sphere.h"
#include "Plane.h"
#include "ShadeRec.h"
#include "Material.h"
#include "Diffusive.h"
#include "Specular.h"
#include "Reflective.h"
#include "Camera.h"

#include "RayTracer.h"



int main(int argc, char *argv[])
{
	const int width = 600;
	const int height = 400;

	const int numSamples = 9;
	int sqSamples = sqrt(numSamples);

	Vector3 origin(0, 0, 0);
	Vector3 target(0, 0, -1);
	Vector3 up(0, 1, 0);

	Camera camera(width, height, origin, target, up, 90.0);

	RayTracer raytracer(width, height, "WriteImage4.ppm");


//	raytracer.addShape(new Sphere(Vector3(0.0, -2.0, -10.0), 3.0,  new Diffusive(Color(1.0, 0.0, 0.0), 0.4)));
	raytracer.addShape(new Sphere(Vector3(0.0, -2.0, -10.0), 3.0,  new Reflective(Color(0.1, 0.1, 0.1), 0.1, 0.6, 0.9, 20)));
	raytracer.addShape(new Sphere(Vector3(7.0, -2.0, -13.0), 3.0,  new Diffusive(Color(0.3, 0.4, 0.1), 0.4)));
	raytracer.addShape(new Sphere(Vector3(-7.0, -2.0, -13.0), 3.0,  new Specular(Color(0.1, 0.3, 0.3), 0.33,  0.6, 20)));
	raytracer.addShape(new Sphere(Vector3(0.0, 4.0, -13.0), 3.0,  new Reflective(Color(0.1, 0.1, 0.1), 0.1, 0.6, 0.6, 20)));
//	raytracer.addShape(new Sphere(Vector3(0.0, -10.0, -10.0), 5, Color(0.5, 0.5, 0.5)));
	raytracer.addShape(new Plane(Vector3(0.0, -5.0, 0.0), Vector3(0.0, 1.0, 0.0), new Diffusive(Color(0.7, 0.7, 0.7), 0.6)));
	raytracer.addLight(new Light(Vector3(0.0, 10, 0.0), Color(1.0, 1.0, 1.0)));
	raytracer.addLight(new Light(Vector3(10.0, 10, -5.0), Color(1.0, 1.0, 1.0)));

	Color pixcolor(0);
	for (int Y = 0; Y < height; ++Y)
	{
		for (int X = 0; X < width; ++X)
		{
			pixcolor = Color(0);

			for (int i = 0; i < sqSamples; ++i)
			{
				for (int j = 0; j < sqSamples; ++j)
				{
					ShadeRec rec(false);
//					Ray camRay = raytracer.castRay(double(X) + (double(i) / double(sqrt(numSamples))), double(Y) + (double(j) / double(sqrt(numSamples)) ));
//					Ray camRay = camera.getRay((double(X) + (double(i) / double(sqrt(numSamples))) / double(width)), (double(Y) + (double(j) / double(sqrt(numSamples))) / double(height)));
					Ray camRay = camera.getRay(double(X) + (double(i) / double(sqSamples)) , double(Y) + (double(j) / double(sqSamples)));

					pixcolor += raytracer.calculate_pixel_color(camRay, 0);
				}
			}
			pixcolor /= numSamples;

			raytracer.image->pixel(X, Y, pixcolor);
		}
	}

	//raytracer.image->clamp(1.0);

	raytracer.write();

	return 0;
}
