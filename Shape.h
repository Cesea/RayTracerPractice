#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "Ray.h"
#include "Color.h"
#include "ShadeRec.h"

/*
	Shape class
	This class is mother class of all hitable object
*/
class Shape
{
public :
	virtual ShadeRec hit(const Ray& ray, double tmin, double tmax) = 0;
	virtual ShadeRec shadowHit(const Ray& ray, double tmin, double tmax) = 0;
};

#endif