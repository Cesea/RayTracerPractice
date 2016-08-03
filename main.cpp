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
#include "Refractive.h"
#include "Camera.h"

#include "Texture.h"
#include "ConstantTexture.h"
#include "CheckerTexture.h"

#include "RayTracer.h"



int main(int argc, char *argv[])
{
	const int width = 300;
	const int height = 200;

	const int numSamples = 9;
	int sqSamples = sqrt(numSamples);

	Vector3 origin(0, 0, 0);
	Vector3 target(0, 0, -1);
	Vector3 up(0, 1, 0);

	Camera camera(width, height, origin, target, up, 90.0);

	RayTracer raytracer(width, height, "WriteImage3.ppm");


//	raytracer.addShape(new Sphere(Vector3(0.0, -2.0, -10.0), 3.0,  new Diffusive(Color(1.0, 0.0, 0.0), 0.4)));
	raytracer.addShape(new Sphere(Vector3(0.0, -2.0, -10.0), 3.0,  new Reflective(new ConstantTexture(Color(0.1, 0.1, 0.1)), 0.1, 0.6, 0.9, 20)));
	raytracer.addShape(new Sphere(Vector3(7.0, -2.0, -13.0), 3.0,  new Diffusive(new ConstantTexture(Color(0.3, 0.4, 0.1)), 0.4)));
	raytracer.addShape(new Sphere(Vector3(-7.0, -2.0, -17.0), 3.0,  new Specular(new ConstantTexture(Color(0.1, 0.3, 0.3)), 0.33,  0.6, 20)));

	raytracer.addShape(new Sphere(Vector3(-7.0, -2.0, -13.0), 3.0,  new Refractive(new ConstantTexture(Color(0.1, 0.1, 0.1)), 0.1,  0.99, 0.4, 20, 1.33)));

	raytracer.addShape(new Sphere(Vector3(0.0, 4.0, -13.0), 3.0,  new Reflective(new ConstantTexture(Color(0.1, 0.1, 0.1)), 0.1, 0.6, 0.6, 20)));
	raytracer.addShape(new Plane(Vector3(0.0, -5.0, 0.0), Vector3(0.0, 1.0, 0.0), new Diffusive(new CheckerTexture(Color(0.1, 0.1, 0.1), Color(0.8, 0.8, 0.1), 2), 0.6)));
	raytracer.addLight(new Light(Vector3(0.0, 10, 0.0), Color(1.3, 1.3, 1.3)));
	raytracer.addLight(new Light(Vector3(10.0, 10, -5.0), Color(1.3, 1.3, 1.3)));

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
