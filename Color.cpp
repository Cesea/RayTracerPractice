#include "Color.h"
/*
	Color functions
*/

Color& Color::clamp()
{
	double max_value = maxd(r, maxd(g, b));
	if (max_value > 1.0)
	{
		r = r / max_value;
		g = g / max_value;
		b = b / max_value;
	}
	return *this;
}