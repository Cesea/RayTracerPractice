#ifndef __COLOR_H__
#define __COLOR_H__

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

		Color(double _f)
			:r(_f), g(_f), b(_f)
		{}

		Color(double _r, double _g, double _b)
			:r(_r), g(_g), b(_b)
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

		void clamp(double max = 1.0)
		{
			if (r > max) r = max;
			if (g > max) r = max;
			if (b > max) r = max;
		}
};

inline Color operator+ (const Color& c1, const Color& c2)
{
	return Color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
}
inline Color operator- (const Color& c1, const Color& c2)
{
	return Color(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
}
#endif