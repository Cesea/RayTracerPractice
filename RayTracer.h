#ifndef __RAY_TRACER_H__
#define __RAY_TRACER_H__

#include <vector>
#include <algorithm>

#include "Constants.h"

#include "Vector3.h"
#include "Color.h"
#include "Image.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Shape.h"
#include "Reflective.h"
#include "Diffusive.h"
#include "Sphere.h"

#include "Light.h"

#define MAX_REFLECTION_DEPTH 5

class RayTracer
{
public :

	//member variable
	int width;
	int height;
	std::vector<Shape *> shapes;
	std::vector<Light *> lights;
	Image *image;
	char *outname;

	//Constrcutor
	RayTracer(int width_,  int height_, char *outname_);

	//Destructor
	~RayTracer();

	//member function
	Ray castRay(double x, double y);
	ShadeRec traceRay(const Ray& ray);
	bool traceShadowRay(const Ray& ray, const ShadeRec& rec);
	Color calculate_pixel_color(const Ray& ray, int iteration);

	Color performLighting(const ShadeRec& rec);
	Color ambientLighting(const ShadeRec& rec);
	Color diffuseAndSpecularLighting(const ShadeRec& rec);
	Color specularLighting(const ShadeRec& rec, Light *light);
	Color reflectionLighting(const ShadeRec& rec, int iteration);

	void write();

	void addShape(Shape *shape);
	void addLight(Light *light);

};

inline void RayTracer::addShape(Shape *shape)
{
	shapes.push_back(shape);
}

inline void RayTracer::addLight(Light* light)
{
	lights.push_back(light);
}

#endif