#include "Material.h"

Material::Material()
	:albedo()
{}

Material::Material(const Color& al)
	: albedo(al)
{}

double Material::getDiffuseCoefficiency() const
{
	return -1;
}

double Material::getSpecularCoefficiency() const
{
	return -1;
}

double Material::getReflectiveCoefficiency() const
{
	return -1;
}

int Material::getShininess() const
{
	return -1;
}