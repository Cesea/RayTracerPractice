#ifndef CONSTANT_TEXTURE_H
#define CONSTANT_TEXTURE_H

#include "Texture.h"

class ConstantTexture : public Texture
{
public :
	Color color;

	ConstantTexture();
	ConstantTexture(const Color& color_);

	virtual Color getColor(const Vector3& hit_point) const;

};

#endif