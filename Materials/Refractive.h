#ifndef REFRACTIVE_H
#define REFRACTIVE_H

#include "Material.h"

class Refractive : public Material
{
public :

	double diffuseCoefficiency;
	double refractiveCoefficiency;
	double specularCoefficiency;
	int shininess;
	double refractiveIndex;

	Refractive();
	Refractive(Texture *albedo_, const double dc, const double rc, const double sc, const int sh, const double ri);

	Ray scatter(const ShadeRec& sr) const;
	double getDiffuseCoefficiency() const;
	double getRefractiveCoefficiency() const;
	double getSpecularCoefficiency() const;
	int getShininess() const;

};


#endif