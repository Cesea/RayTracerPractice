#include "Diffusive.h"

Diffusive::Diffusive()
	:Material::Material()
{}


Diffusive::Diffusive(const Color& al, const double& dc)
	:Material::Material(al), diffuseCoefficient(dc)
{}

Ray Diffusive::scatter(const ShadeRec& sr) const
{
	Vector3 p;
	do
	{
		p = 2.0 * Vector3(rand_double(), rand_double(), rand_double()) - Vector3(1, 1, 1);
	} while (p.length_squared() > 1.0);
	Vector3 direction;
	direction = (sr.hit_point + sr.normal + p) - sr.hit_point;
	direction = normalize(direction);

	Vector3 origin(sr.hit_point + EPSILON * direction);

	return Ray(origin, direction);
}

double Diffusive::getDiffuseCoefficiency() const
{
	return diffuseCoefficient;
}