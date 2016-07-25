#include "Vector3.h"


Vector3& Vector3::operator += (const Vector3& v)
{
	_x += v._x; _y += v._y; _z += v._z;
	return *this;
}
Vector3& Vector3::operator -= (const Vector3& v)
{
	_x += v._x; _y += v._y; _z += v._z;
	return *this;
}

Vector3& Vector3::operator *= (const double d)
{
	_x *= d; _y *= d; _z *= d;
	return *this;
}
Vector3& Vector3::operator /= (const double d)
{
	_x /= d; _y /= d; _z *= d;
	return *this;
}

//Length function
double Vector3::length()
{
	return sqrt(_x*_x + _y*_y + _z*_z);
}
//Length squared function
double Vector3::length_squared()
{
	return _x*_x + _y*_y + _z*_z;
}

void Vector3::normalize()
{
	float k = 1.0 / sqrt(_x*_x + _y*_y + _z*_z);
	_x *= k; _y *= k; _z *= k;
}