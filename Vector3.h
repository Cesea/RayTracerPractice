#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <math.h>

class Vector3
{
public :
	double _x, _y, _z;

// Constructors
	Vector3()
		:_x(), _y(), _z()
	{}

	Vector3(double a)
		: _x(a), _y(a), _z(a)
	{}

	Vector3(double x_, double y_, double z_)
		:_x(x_), _y(y_), _z(z_)
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
	return Vector3(v1._x + v2._x, v1._y + v2._y, v1._z + v2._z);
}
inline Vector3 operator - (const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1._x - v2._x, v1._y - v2._y, v1._z - v2._z);
}
inline Vector3 operator * (const Vector3& v1, const double d)
{
	return Vector3(v1._x * d, v1._y * d, v1._z * d);
}
inline Vector3 operator * (const double d, const Vector3& v1)
{
	return Vector3(v1._x * d, v1._y * d, v1._z * d);
}
inline Vector3 operator / (const Vector3& v1, const double d)
{
return Vector3(v1._x / d, v1._y / d, v1._z / d);
}

inline Vector3 normalize(Vector3 v)
{
	return v / v.length();
}
#endif