#include "Material.h"

Material::Material()
	:albedo()
{}

Material::Material(Texture *albedo_)
	: albedo(albedo_)
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

double Material::getRefractiveCoefficiency() const
{
	return -1;
}