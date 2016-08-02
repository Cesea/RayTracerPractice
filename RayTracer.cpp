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

Ray RayTracer::castRay(double x, double y)
{
	/*orthogonal
	int rayX = x - width / 2;
	int rayY = y - height / 2;

	Vector3 origin(rayX, rayY, 0);
	Vector3 direction(0, 0, -1);
	return Ray(origin, direction);
	*/
	double u = (x) / double(width);
	double v = (y) / double(height);

	Vector3 origin(0, 0, 0);
	Vector3 upper_left(-1.0, 1.0, -1.0);
	Vector3 horizontal(2.0, 0.0, 0.0);
	Vector3 vertical(0.0, 2.0, 0.0);
	Vector3 direction = normalize(upper_left + horizontal * u - vertical * v - origin);
	Ray ray(origin, direction);
	return ray;
}

ShadeRec RayTracer::traceRay(const Ray& ray)
{
	double closest_t = MAX;
	ShadeRec rec(false);
	for (int i = 0; i < shapes.size(); ++i)
	{
		ShadeRec temp(false); 
		temp = shapes[i]->hit(ray, EPSILON, closest_t);
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
		if (shadowRec.hit &&  shadowRec.t < closest_t && shadowRec.shape != rec.shape)
		{
			temp = true;
			break;
		}
		else
		{
			continue;
		}
	}
	return temp;
}

Color RayTracer::ambientLighting(const ShadeRec& rec)
{
	Color retColor;
	retColor += rec.shape->mat->albedo * 0.1;
	return retColor;
}

Color RayTracer::diffuseAndSpecularLighting(const ShadeRec& rec)
{
	Color retColor;
	for (int i = 0; i < lights.size(); ++i)
	{
		Light* light = lights[i];
		Vector3 lightDirection = normalize(light->position - rec.hit_point);
		if (traceShadowRay(Ray(Vector3(rec.hit_point + EPSILON * lightDirection), lightDirection), rec))
		{
			//in shadow
			continue;
		}
		else
		{
			//caucluate diffuse
			double LDotN = std::max(0.0, dot(lightDirection, rec.normal));
			if (LDotN > 0.0)
			{
				retColor += rec.shape->mat->albedo * LDotN *
					rec.shape->mat->getDiffuseCoefficiency() * light->color;
			}
			//calculate Specular
			retColor += specularLighting(rec, light);
		}
	}
	return retColor;
}

Color RayTracer::specularLighting(const ShadeRec& rec, Light *light)
{
	Color retColor(0);
	double specularCoefficiency = rec.shape->mat->getSpecularCoefficiency();
	if (specularCoefficiency < 0.0)
	{
		return retColor;
	}
	else
	{
		Vector3 lightDirection = normalize(light->position - rec.hit_point);
		Vector3 halfVector = ((-rec.ray.direction + lightDirection) / 2.0);
		double HDotN = std::max(0.0, dot(rec.normal, halfVector));
		if (HDotN > 0.0)
		{
			double power = pow(HDotN, rec.shape->mat->getShininess()) * specularCoefficiency;
			retColor.r = power;
			retColor.g = power;
			retColor.b = power;
		}

		return retColor;
	}
}


Color RayTracer::calculate_pixel_color(const Ray& ray, int iteration)
{
	Color retColor(0);

	ShadeRec rec(false);
	rec = traceRay(ray);
	Light* light = nullptr;

	if (rec.hit  && rec.shape != nullptr)
	{
		//ambient light
		retColor += ambientLighting(rec);
		retColor += diffuseAndSpecularLighting(rec);
#if 0
		//diffuse color calculation
		for (int i = 0; i < lights.size(); ++i)
		{
			light = lights[i];
			Vector3 lightDirection = normalize(light->position - rec.hit_point);

			
			
			if (traceShadowRay(Ray(Vector3(rec.hit_point + EPSILON * lightDirection), lightDirection), rec))
			{
				//in shadow
				continue;
			}
			else
			{
				//caucluate diffuse
				double LDotN = std::max(0.0, dot(lightDirection, rec.normal));
				if (LDotN > 0.0)
				{
					retColor += rec.shape->mat->albedo * LDotN * 0.6;
				}

				//calculate specular
//				Vector3 R = 2 * dot(rec.normal, -rec.ray.direction) * rec.normal + rec.ray.direction;
				if (rec.shape->mat->getSpecularCoefficiency() > 0.0)
				{
					Vector3 sD = normalize((lightDirection + (-rec.ray.direction)) / 2.0);
					double SDotN = std::max(0.0, dot(sD, rec.normal));
					if (SDotN > 0.0)
					{
						retColor += Color(0.8) * SDotN * rec.shape->mat->getSpecularCoefficiency();
					}
				}

			}
		}

		if (rec.shape->mat->getReflectiveCoefficeincy() > 0.0)
		{
			Ray newRay = rec.shape->mat->scatter(rec);
			retColor += calculate_pixel_color(newRay, ++iteration) * rec.shape->mat->getReflectiveCoefficeincy();
		}
#endif
//		Ray newRay = rec.shape->mat->scatter(rec);
		return retColor;
	}
	else
	{
		Vector3 unit_direction = normalize(ray.direction);
		float t = 0.5 * (unit_direction.y + 1.0);
		return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
	}
//	return retColor + rec.shape->mat->albedo * 0.1;
}

void RayTracer::write()
{
	image->WritePPM(outname);
}