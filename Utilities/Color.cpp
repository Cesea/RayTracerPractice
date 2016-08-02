#include "Color.h"
/*
	Color functions
*/

Color& Color::clamp()
{
	/*
	double max_value = maxd(r, maxd(g, b));
	if (max_value > 1.0)
	{
		r = r / max_value;
		g = g / max_value;
		b = b / max_value;
	}
	*/

	if (r > 1.0) r = 1.0;
	if (g > 1.0) g = 1.0;
	if (b > 1.0) b = 1.0;


	return *this;
}