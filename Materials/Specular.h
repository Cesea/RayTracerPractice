#ifndef SPECULAR_H
#define SPECULAR_H

#include "Material.h"

class Specular : public Material
{
public:
	double diffuseCoefficiency;
	double specularCoefficiency;
	int shininess;

	Specular();
	Specular( Texture *albedo_, const double dc, const double sc, const int sh);

	Ray scatter(const ShadeRec& sr) const;
	double getDiffuseCoefficiency() const;
	double getSpecularCoefficiency() const;
	int getShininess() const;

};

#endif