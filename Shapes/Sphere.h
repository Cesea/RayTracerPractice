#ifndef __SPHERE_H__
#define  __SPHERE_H__

#include "Shape.h"

class Sphere : public Shape
{
public :
	Vector3 center;
	double radius;

	Sphere()
		:center(), radius(),  Shape::Shape()
	{}

	Sphere(Vector3& center_, double radius_,  Material* m_)
		:center(center_), radius(radius_),  Shape::Shape(m_)
	{}

	virtual ShadeRec hit(const Ray& ray, double tmin, double tmax) ;
	virtual ShadeRec shadowHit(const Ray& ray, double tmin, double tmax);

};

#endif