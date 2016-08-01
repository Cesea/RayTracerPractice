#ifndef REFLECTIVE_H
#define REFLECTIVE_H

#include "Material.h"

class Reflective : public Material
{
public :
	double reflectiveCoefficiency;
	double specularCoefficiency;
	int falloff;

	Reflective();
	Reflective(const Color& al, const double rc, const double sc, const int fo);

	Ray scatter(const ShadeRec& sr) const;
	double getReflectiveCoefficeincy() const;
	double getSpecularCoefficiency() const;
	int getFalloff() const;
};

#endif