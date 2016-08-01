#include "Plane.h"

ShadeRec Plane::hit(const Ray& ray, double tmin, double tmax)
{
	ShadeRec rec(false);
	Vector3 o_minus_c = ray.origin - origin;
	float d_dot_n = dot(ray.direction, normal);
	if (d_dot_n == 0)
		return rec;

	float t = -dot(o_minus_c, normal) / d_dot_n;
	if (t > tmin && t < tmax)
	{
		rec.normal = normal;
		rec.t = t;
		rec.hit_point = ray.calculate_point(t);
		rec.shape = this;
		rec.ray = ray;
		rec.hit = true;
		return rec;
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
		rec.shape = this;
		return rec;
	}
	else
	{
		return rec;
	}
	return rec;

}
