#ifndef __SHADEREC_H__
#define __SHADEREC_H__

#include "Vector3.h"

/*
	This class Will be used to Shade objects
*/
class ShadeRec
{
public :

	bool hit;
	Vector3 hit_point;
	Vector3 normal;
	Color color;

	ShadeRec()
		:hit(false), hit_point(), normal(), color()
	{}
};

#endif