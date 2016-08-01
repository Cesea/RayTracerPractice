
#include "Camera.h"
Camera::Camera(int width_, int height_, Vector3 eye_, Vector3 target_, Vector3 up_, double fov_)
	:origin(eye_), fov(fov_), width(width_), height(height_), tanfov()
{
	w = normalize(origin - target_);
	u = normalize(cross(up_, w));
	v = normalize(cross(w, u));
	aspectRatio = double(width) / double(height);
	double theta = fov * (M_PI / 180.0);
	tanfov = tan(theta / 2);

	
	u = u * aspectRatio * tanfov;
	v = v * tanfov;

	upper_left = -u + v;
	horizontal = Vector3();
}
Ray Camera::getRay(int X, int Y)
{
	Ray retRay;
	retRay.origin = origin;
	Vector3 direction = -u + v - w;
	/*
	double udir = (2.0 * (double(X) / double(width)) - 1);
	double vdir = 1.0 - 2.0*(double(Y) / double(height));
	*/
	double udir = double(X) / double(width);
	double vdir = double(Y) / double(height);
	direction += (udir * u * 2 - vdir * v * 2) ;
	direction = normalize(direction);
	retRay.direction = direction;
	return retRay;
}