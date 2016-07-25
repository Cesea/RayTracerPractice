#include "Sphere.h"

ShadeRec Sphere::hit(const Ray& ray, double tmin, double tmax) const
{
	ShadeRec rec;

	Vector3 o_minus_c = ray.origin - center;
	double a = dot(ray.direction, ray.direction);
	double b = 2 * dot(ray.direction, o_minus_c);
	double c = dot(o_minus_c, o_minus_c) - radius*radius;

	double discriminant = b*b - 4 * a*c;
	// if discriminant > 0 then it hits
	if (discriminant > 0)
	{
		discriminant = sqrt(discriminant);
		double t;
		t = (-b - discriminant) / (2 * a);
		if (t > tmin && t < tmax)
		{
			rec.hit = true;
			rec.t = t;
			rec.color = color;
			rec.hit_point = ray.calculate_point(t);
			rec.normal = (rec.hit_point - center) / radius;
			return rec;
		}
		t = (-b + discriminant) / (2 * a);
		if (t > tmin && t < tmax)
		{
			rec.hit = true;
			rec.t = t;
			rec.color = color;
			rec.hit_point = ray.calculate_point(t);
			rec.normal = (rec.hit_point - center) / radius;
			return rec;
		}
	}
	else
	{
		rec.hit = false;
		return rec;
	}
}
