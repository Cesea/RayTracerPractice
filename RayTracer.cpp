#include "RayTracer.h"

RayTracer::RayTracer(int width_, int height_, char *outname_)
{
	image = new Image(width_, height_);
	outname = outname_;
}

RayTracer::~RayTracer()
{
	free(image);
}

Ray RayTracer::castRay(int width_, int height_)
{
	Vector3 origin(width_, height_, 0);
	Vector3 direction(0, 0, -1);
	return Ray(origin, direction);
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

void RayTracer::write()
{
	image->WritePPM(outname);
}