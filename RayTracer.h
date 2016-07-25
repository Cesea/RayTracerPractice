#ifndef __RAY_TRACER_H__
#define __RAY_TRACER_H__

#include <vector>

#include "Constants.h"

#include "Vector3.h"
#include "Color.h"
#include "Image.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Shape.h"
#include "Sphere.h"

#include "Light.h"



class RayTracer
{
public :

	//member variable
	std::vector<Shape *> shapes;
	std::vector<Light *> lights;
	Image *image;
	char *outname;

	//Constrcutor
	RayTracer(int width_,  int height_, char *outname_);

	//Destructor
	~RayTracer();

	//member function
	Ray castRay(int width_, int height_);
	ShadeRec traceRay(const Ray& ray);
	Color calculate_pixel_color(const ShadeRec& rec);
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