#include "ConstantTexture.h"

ConstantTexture::ConstantTexture()
	:color()
{}

ConstantTexture::ConstantTexture(const Color& color_)
	: color(color_)
{}

Color ConstantTexture::getColor(const Vector3& hit_point) const
{
	return color;
}