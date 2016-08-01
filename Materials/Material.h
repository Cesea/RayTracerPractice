#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "Color.h"
#include "Vector3.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Constants.h"

#include "MathLib.h"

class Material
{
public :
	Color albedo;

	Material();
	Material(const Color& al);

	virtual Ray scatter(const ShadeRec& sr) const = 0;
	virtual double getDiffuseCoefficiency() const;
	virtual double getSpecularCoefficiency() const;
	virtual double getReflectiveCoefficeincy() const;
	virtual int getFalloff() const;
};


#endif