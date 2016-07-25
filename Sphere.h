#ifndef __SPHERE_H__
#define  __SPHERE_H__

#include "Shape.h"

class Sphere
{
public :
	Vector3 center;
	double radius;
	Color color;

	Sphere()
		:center(), radius(), color()
	{}

	Sphere(Vector3& center_, double radius_, Color& color_)
		:center(center_), radius(radius_), color(color_)
	{}

	virtual ShadeRec hit(const Ray& ray) const;

};

#endif