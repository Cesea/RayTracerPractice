#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "Constants.h"
#include "Vector3.h"

class Light
{
public :

	Vector3 position;

	Light()
		:position()
	{}

	Light(Vector3 position_)
		:position(position_)
	{}
};

#endif