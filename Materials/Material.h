#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "Color.h"
#include "Vector3.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Constants.h"
#include "Texture.h"

#include "MathLib.h"

class Material
{
public :
	Texture *albedo;

	Material();
	Material(Texture* albedo_);

	virtual Ray scatter(const ShadeRec& sr) const = 0;
	virtual double getDiffuseCoefficiency() const;
	virtual double getSpecularCoefficiency() const;
	virtual double getReflectiveCoefficiency() const;
	virtual int getShininess() const;
};


#endif