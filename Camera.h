#ifndef _CAMERA_H
#define _CAMERA_H
#define M_PI 3.141592653

#include "Vector3.h"
#include "Ray.h"
class Camera
{
public:
	Vector3 u, v, w;
	Vector3 origin;
	Vector3 upper_left;
	Vector3 horizontal;
	Vector3 vertical;
	double fov;
	int width;
	int height;
	double aspectRatio;
	double tanfov;
	Camera();
	Camera(int width_, int height_, Vector3 eye_, Vector3 target_, Vector3 up_, double fov_);
	Ray getRay(double X, double Y);
};

#endif