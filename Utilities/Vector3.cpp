#include "Vector3.h"


Vector3& Vector3::operator += (const Vector3& v)
{
	x += v.x; y += v.y; z += v.z;
	return *this;
}
Vector3& Vector3::operator -= (const Vector3& v)
{
	x += v.x; y += v.y; z += v.z;
	return *this;
}

Vector3& Vector3::operator *= (const double d)
{
	x *= d; y *= d; z *= d;
	return *this;
}
Vector3& Vector3::operator /= (const double d)
{
	x /= d; y /= d; z *= d;
	return *this;
}

//Length function
double Vector3::length()
{
	return sqrt(x*x + y*y + z*z);
}
//Length squared function
double Vector3::length_squared()
{
	return x*x + y*y + z*z;
}

void Vector3::normalize()
{
	double k = 1.0 / sqrt(x*x + y*y + z*z);
	x *= k; y *= k; z *= k;
}