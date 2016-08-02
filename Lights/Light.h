#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "Constants.h"
#include "Color.h"
#include "Vector3.h"

class Light
{
public :

	Vector3 position;
	Color color;

	Light()
		:position(), color()
	{}

	Light(const Vector3& position_, const Color& color_ )
		:position(position_), color(color_)
	{}
};

#endif