#ifndef TEXTURE_H
#define TEXTURE_H

#include "Color.h"
#include "Vector3.h"
#include "ShadeRec.h"

class Texture
{
public :
	virtual Color getColor(const Vector3& hit_point) const = 0;


};

#endif