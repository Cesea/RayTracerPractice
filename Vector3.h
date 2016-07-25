#ifndef VECTORH
#define VECTORH

#include <math.h>

class Vector3
{
public :
	double x, y, z;

// Constructors
	Vector3()
		:x(), y(), z()
	{}

	Vector3(double a)
		: x(a), y(a), z(a)
	{}

	Vector3(double x_, double y_, double z_)
		:x(x_), y(y_), z(z_)
	{}

	Vector3& operator += (const Vector3& v);
	Vector3& operator -= (const Vector3& v);
	Vector3& operator *= (const double d);
	Vector3& operator /= (const double d);

	double length();
	double length_squared();
	void normalize();

};

inline Vector3 operator + (const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
inline Vector3 operator - (const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
inline Vector3 operator * (const Vector3& v1, const double d)
{
	return Vector3(v1.x * d, v1.y * d, v1.z * d);
}
inline Vector3 operator * (const double d, const Vector3& v1)
{
	return Vector3(v1.x * d, v1.y * d, v1.z * d);
}
inline Vector3 operator / (const Vector3& v1, const double d)
{
return Vector3(v1.x / d, v1.y / d, v1.z / d);
}

inline Vector3 normalize(Vector3 v)
{
	return v / v.length();
}
#endif