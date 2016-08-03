#include "CheckerTexture.h"

CheckerTexture::CheckerTexture()
	:odd(nullptr), even(nullptr), ratio(1)
{
	odd = new ConstantTexture(Color(0, 0, 0));
	even = new ConstantTexture(Color(1, 1, 1));
}

CheckerTexture::CheckerTexture(const Color& c1, const Color& c2, float ratio_)
	:odd(nullptr), even(nullptr), ratio(ratio_)
{
	odd = new ConstantTexture(c1);
	even = new ConstantTexture(c2);
}

CheckerTexture::CheckerTexture(ConstantTexture * odd_, ConstantTexture *even_, float ratio_)
	:odd(odd_), even(even_), ratio(ratio_)
{}

Color CheckerTexture::getColor(const Vector3& hit_point) const
{
	float x = sinf(float(hit_point.x * ratio));
	float y = sinf(float(hit_point.y * ratio));
	float z = sinf(float(hit_point.z * ratio));
	if (x * y * z < 0)
	{
		return odd->getColor(hit_point);
	}
	else
	{
		return even->getColor(hit_point);
	}
}

