#include "RayTracer.h"

RayTracer::RayTracer(int width_, int height_, char *outname_)
	:width(width_), height(height_)
{
	image = new Image(width_, height_);
	outname = outname_;
}

RayTracer::~RayTracer()
{
	free(image);
}

Ray RayTracer::castRay(int x, int y)
{
	/*orthogonal
	int rayX = x - width / 2;
	int rayY = y - height / 2;

	Vector3 origin(rayX, rayY, 0);
	Vector3 direction(0, 0, -1);
	return Ray(origin, direction);
	*/
	double u = double(x) / double(width);
	double v = double(y) / double(height);

	Vector3 origin(0, 0, 0);
	Vector3 upper_left(-1.0, 1.0, -1.0);
	Vector3 horizontal(2.0, 0.0, 0.0);
	Vector3 vertical(0.0, 2.0, 0.0);
	Vector3 direction = normalize(upper_left + horizontal * u - vertical * v);
	Ray ray(origin, direction);
	return ray;
}

ShadeRec RayTracer::traceRay(const Ray& ray)
{
	double closest_t = MAX;
	ShadeRec rec;
	for (int i = 0; i < shapes.size(); ++i)
	{
		ShadeRec temp = shapes[i]->hit(ray, EPSILON, closest_t);
		if (temp.hit && temp.t < closest_t)
		{
			closest_t = temp.t;
			rec = temp;
		}
	}
	return rec;
}

bool RayTracer::traceShadowRay(const Ray& ray, const ShadeRec& rec)
{
	bool temp = false;
	double closest_t = MAX;
	for (int i = 0; i < shapes.size(); ++i)
	{
		ShadeRec shadowRec = shapes[i]->shadowHit(ray, EPSILON, closest_t);
		if (shadowRec.hit &&  rec.t < closest_t && shadowRec.shape != rec.shape)
		{
			closest_t = rec.t;
			return true;
		}
		else
		{
			return false;
		}
	}
}


Color RayTracer::calculate_pixel_color(const ShadeRec& rec)
{
	Color retColor(0);

	for (int i = 0; i < lights.size(); ++i)
	{
		Light *temp = lights[i];
		Vector3 toLight = (temp->position - rec.hit_point);
		Vector3 lightDirection = normalize(toLight);
		double LdotN = dot(lightDirection, rec.normal);

		if (LdotN >= 0.0 )
		{
			/* i have to fix Shadow*/
			Ray shadowRay(rec.hit_point + lightDirection, lightDirection);
			if (traceShadowRay(shadowRay, rec))
			{
				retColor += Color(0);
			}
			else
			{
				retColor += rec.color * LdotN;
			}
		}
	}
	retColor += rec.color * 0.2;
	return retColor;
}

void RayTracer::write()
{
	image->WritePPM(outname);
}