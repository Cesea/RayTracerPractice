#ifndef REFLECTIVE_H
#define REFLECTIVE_H

#include "Material.h"

class Reflective : public Material
{
public :
	double reflectiveCoefficiency;
	double specularCoefficiency;
	int shininess;

	Reflective();
	Reflective(const Color& al, const double rc, const double sc, const int sh);

	Ray scatter(const ShadeRec& sr) const;
	double getReflectiveCoefficeincy() const;
	double getSpecularCoefficiency() const;
	int getShininess() const;
};

#endif