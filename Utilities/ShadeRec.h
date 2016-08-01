#ifndef __SHADEREC_H__
#define __SHADEREC_H__

#include "Vector3.h"
#include "Ray.h"

class Shape;
/*
	This class Will be used to Shade objects
*/
class ShadeRec
{
public :

	bool hit;
	double t;
	Ray ray;
	Vector3 hit_point;
	Vector3 normal;
	Shape* shape;

	ShadeRec()
		:hit(false), t(), hit_point(), normal(), shape(NULL), ray()
	{}

	ShadeRec(bool hit_)
		:hit(hit_), t(), hit_point(), normal(), shape(NULL), ray()
	{}
};

#endif