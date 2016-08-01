#include "Reflective.h"


Reflective::Reflective()
	:Material::Material()
{}

Reflective::Reflective(const Color& al, const double rc, const double sc, const int fo)
	: Material::Material(al), reflectiveCoefficiency(rc), falloff(fo), specularCoefficiency(sc)
{}

Ray Reflective::scatter(const ShadeRec& sr) const
{
	Vector3 refDirection = sr.ray.direction + 2.0 * dot(-sr.ray.direction, sr.normal) * sr.normal;
	Ray retRay(sr.hit_point + EPSILON * refDirection, refDirection);
	return retRay;
}

double Reflective::getSpecularCoefficiency() const
{
	return specularCoefficiency;
}

double Reflective::getReflectiveCoefficeincy() const
{
	return reflectiveCoefficiency;
}

int Reflective::getFalloff() const
{
	return falloff;
}