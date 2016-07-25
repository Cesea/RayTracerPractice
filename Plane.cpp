#include "Plane.h"

ShadeRec Plane::hit(const Ray& ray, double tmin, double tmax)
{
	ShadeRec rec;
	Vector3 o_minus_c = ray.origin - origin;
	float d_dot_n = dot(ray.direction, normal);
	if (d_dot_n == 0)
		return false;

	float t = -dot(o_minus_c, normal) / d_dot_n;
	if (t > tmin && t < tmax)
	{
		rec.normal = normal;
		rec.t = t;
		rec.hit_point = ray.calculate_point(t);
		rec.color = color;
		rec.shape = this;
		rec.hit = true;
	}
	return rec;
}

ShadeRec Plane::shadowHit(const Ray& ray, double tmin, double tmax)
{
	ShadeRec rec(false);
	Vector3 o_minus_c = ray.origin - origin;
	float d_dot_n = dot(ray.direction, normal);
	if (d_dot_n == 0)
	{
		return rec;
	}

	float t = -dot(o_minus_c, normal) / d_dot_n;
	if (t > tmin && t < tmax)
	{
		rec.hit = true;
		rec.t = t;
	}
	else
	{
		return rec;
	}
	return rec;

}