#ifndef CHECKER_TEXTURE_H
#define CHECKER_TEXTURE_H

#include "Texture.h"
#include "ConstantTexture.h"

#include <math.h>

class CheckerTexture : public Texture
{
public :

	ConstantTexture *odd;
	ConstantTexture *even;
	float ratio;

	CheckerTexture();
	CheckerTexture(const Color& c1, const Color& c2, float ratio_);
	CheckerTexture(ConstantTexture *odd_, ConstantTexture *even_, float ratio_);

	virtual Color getColor(const Vector3& hit_point) const;
};

#endif