#ifndef __COLOR_H__
#define __COLOR_H__

#include <algorithm>

static double maxd(double a, double b)
{
	return a > b ? a : b;
}

//Color Class
class Color
{

	public :
		double r;
		double g; 
		double b;

		Color()
			:r(0), g(0), b(0) 
		{}

		Color(double f_)
			:r(f_), g(f_), b(f_)
		{}

		Color(double r_, double g_, double b_)
			:r(r_), g(g_), b(b_)
		{}

		inline Color& operator += (const Color& c)
		{
			r += c.r; g += c.g; b += c.b;
			return *this;
		}

		inline Color& operator *= (const double d)
		{
			r *= d; g *= d; b *= d;
			return *this;
		}

		inline Color& operator *= (const Color& c)
		{
			r *= c.r; g *= c.g; b *= c.b;
			return *this;
		}

		inline Color& operator /= (const double d)
		{
			r /= d; g /= d; b /= d;
			return *this;
		}

		Color& clamp();
		
};

inline Color operator+ (const Color& c1, const Color& c2)
{
	return Color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
}
inline Color operator- (const Color& c1, const Color& c2)
{
	return Color(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
}

inline Color operator * (const Color& c, const double d)
{
	return Color(c.r*d, c.g*d, c.b*d);
}
inline Color operator * (const double d, const Color& c)
{
	return Color(c.r*d, c.g*d, c.b*d);
}

inline Color operator * (const Color& c1, const Color& c2)
{
	return Color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
}

inline Color operator / (const Color& c, const double d)
{
	return Color(c.r / d, c.g / d, c.b / d);
}

inline Color operator > (const Color& c, const double d)
{
	if (c.r > d || c.g > d || c.b > d) return true;
}

inline Color operator < (const Color& c, const double d)
{
	if (c.r < d || c.g < d || c.b < d) return true;
}

#endif