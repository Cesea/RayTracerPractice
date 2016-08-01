#include "Material.h"

Material::Material()
	:albedo()
{}

Material::Material(const Color& al)
	: albedo(al)
{}

double Material::getDiffuseCoefficiency() const
{
	return -0;
}

double Material::getSpecularCoefficiency() const
{
	return -0;
}

double Material::getReflectiveCoefficeincy() const
{
	return -0;
}

int Material::getFalloff() const
{
	return -0;
}