#include "Reflective.h"


Reflective::Reflective()
	:Material::Material(), diffuseCoefficiency(), reflectiveCoefficiency(), specularCoefficiency()
{}

Reflective::Reflective(Texture *albedo_, const double dc, const double rc, const double sc, const int sh)
	: Material::Material(albedo_), diffuseCoefficiency(dc), reflectiveCoefficiency(rc), shininess(sh), specularCoefficiency(sc)
{}

Ray Reflective::scatter(const ShadeRec& sr) const
{
	Vector3 refDirection = normalize(sr.ray.direction + 2.0 * dot(-sr.ray.direction, sr.normal) * sr.normal);
	Ray retRay(sr.hit_point + EPSILON * refDirection, refDirection);
	return retRay;
}

double Reflective::getDiffuseCoefficiency() const
{
	return diffuseCoefficiency;
}

double Reflective::getSpecularCoefficiency() const
{
	return specularCoefficiency;
}

double Reflective::getReflectiveCoefficiency() const
{
	return reflectiveCoefficiency;
}

int Reflective::getShininess() const
{
	return shininess;
}