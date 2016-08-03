#ifndef VECTORH
#define VECTORH

#include <math.h>

/*
	Basic Vector3 class
*/
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

	Vector3 operator-() const
	{
		return Vector3(-x, -y, -z);
	}

	Vector3& operator += (const Vector3& v);
	Vector3& operator -= (const Vector3& v);
	Vector3& operator *= (const double d);
	Vector3& operator /= (const double d);

	

	double length();
	double length_squared();
	void normalize();

}; //Vector3

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

//Dot product
inline double dot(const Vector3& v1, const Vector3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

//Cross product
inline Vector3 cross(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.y*v2.z - v1.z*v2.y,
					v1.z*v2.x - v1.x*v2.z,
					v1.x*v2.y - v1.y*v2.x);
}

inline bool operator == (const Vector3& v1, const Vector3& v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return true;
	else
		return false;
}

static Vector3 getReflect(const Vector3& incident, const Vector3& normal)
{
	Vector3 retVec;
	retVec = 2 * dot(-incident, normal) * normal + incident;
	return retVec;
}

static bool getRefract(const Vector3& incident, const Vector3& normal, double index, Vector3& refracted)
{
	Vector3 ui = normalize(incident);
	double IDotN = dot(-ui, normal);
	double n1_over_n2 = index;
	double discriminant = 1.0 - n1_over_n2 * n1_over_n2 * (1 - IDotN * IDotN);
	if (discriminant > 0)
	{
		refracted = n1_over_n2 * (incident + normal * IDotN) - normal * sqrt(discriminant);
		return true;
	}
	else
	{
		return false;
	}
}


#endif