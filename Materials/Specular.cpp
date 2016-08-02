#include "Specular.h"


Specular::Specular()
	: Material::Material(), specularCoefficiency(), shininess(), diffuseCoefficiency()
{}

Specular::Specular(const Color& al, const double dc, const double sc, const int sh)
	: Material::Material(al), diffuseCoefficiency(dc), specularCoefficiency(sc), shininess(sh)
{}

Ray Specular::scatter(const ShadeRec& sr) const
{
	return Ray();
}

double Specular::getDiffuseCoefficiency() const
{
	return diffuseCoefficiency;
}

double Specular::getSpecularCoefficiency() const
{
	return specularCoefficiency;
}
int Specular::getShininess() const
{
	return shininess;
}