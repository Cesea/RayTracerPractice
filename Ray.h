#ifndef __RAY_H__
#define __RAY_H__

#include "Vector3.h"

/*
	Ray class
*/
class Ray
{
public :
	Vector3 origin;
	Vector3 direction;

	Ray()
		:origin(), direction()
	{}

	Ray(const Vector3& origin_, const Vector3& direction_)
		:origin(origin_), direction(direction_)
	{}

	//member function
	Vector3 calculate_point(double t) const
	{
		return origin + (direction * t);
	}
}; //Ray class


#endif