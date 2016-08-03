#include "Refractive.h"

Refractive::Refractive()
	: Material::Material()
{}

Refractive::Refractive(Texture *albedo_, const double dc, const double rc, const double sc, const int sh, const double ri)
	: Material::Material(albedo_), diffuseCoefficiency(dc), refractiveCoefficiency(rc), specularCoefficiency(sc), shininess(sh), refractiveIndex(ri)
{}

Ray Refractive::scatter(const ShadeRec& sr) const
{
	Ray retRay;
	Vector3 outNormal = sr.normal;
	double index = refractiveIndex;
	if (dot(sr.ray.direction, sr.normal) > 0)
	{
		outNormal = -outNormal;
		index = 1.0 / index;
	}
	else
	{
	}
	Vector3 refract;
	if (getRefract(sr.ray.direction, sr.normal, index, refract))
	{
		retRay.origin = sr.hit_point;
		retRay.direction = refract;
	}
	else
	{
	}

	return retRay;
}

double Refractive::getDiffuseCoefficiency() const
{
	return diffuseCoefficiency;
}

double Refractive::getRefractiveCoefficiency() const
{
	return refractiveCoefficiency;
}

double Refractive::getSpecularCoefficiency() const
{
	return specularCoefficiency;
}

int Refractive::getShininess() const
{
	return shininess;
}
