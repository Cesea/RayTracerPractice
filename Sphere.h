#ifndef __SPHERE_H__
#define  __SPHERE_H__

#include "Shape.h"

class Sphere
{
public :
	Vector3 center;
	double radius;

	Sphere()
		:center(), radius()
	{}

	Sphere(Vector3 center_, double radius_)
		:center(center_), radius(radius_)
	{}

	virtual bool hit(const Ray& ray) const;

};

#endif