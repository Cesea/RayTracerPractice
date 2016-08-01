#ifndef __PLANE_H__
#define __PLANE_H__

#include "Shape.h"

class Plane : public Shape
{
public :

	Vector3 origin;
	Vector3 normal;

	Plane()
		:origin(), normal(), Shape::Shape()
	{}

	Plane(Vector3& origin_, Vector3& normal_, Material* m_)
		:origin(origin_), normal(normal_), Shape::Shape(m_)
	{}

	virtual ShadeRec hit(const Ray& ray, double tmin, double tmax);
	virtual ShadeRec shadowHit(const Ray& ray, double tmim, double tmax);

};

#endif