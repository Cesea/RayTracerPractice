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

Color RayTracer::traceRay(const Ray& ray)
{
	for (int i = 0; i < shapes.size(); ++i)
	{
		ShadeRec rec = shapes[i]->hit(ray);
		if (rec.hit)
		{
			return rec.color;
		}
	}
	return Color(0);
}

void RayTracer::write()
{
	image->WritePPM(outname);
}