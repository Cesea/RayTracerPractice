#include "Sphere.h"

ShadeRec Sphere::hit(const Ray& ray) const
{
	ShadeRec rec;

	Vector3 o_minus_c = ray.origin - center;
	double a = dot(ray.direction, ray.direction);
	double b = 2 * dot(ray.direction, o_minus_c);
	double c = dot(o_minus_c, o_minus_c) - radius*radius;

	double discriminant = b*b - 4 * a*c;
	if (discriminant > 0)
	{
		rec.hit = true;
		return rec;
		/*
			Calculation code	
		*/	
	}

	else
	{
		rec.hit = false;
		return rec;
	}
}
