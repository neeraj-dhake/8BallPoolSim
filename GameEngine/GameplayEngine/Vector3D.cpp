#include "Vector3D.h"
#include <math.h>

Vector3D::Vector3D(float X,float Y, float Z) {
	x = X;
	y = Y;
	z = Z;
}

Vector3D & Vector3D::operator=(const Vector3D& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
	return Vector3D(x + v.x, y + v.y,z + v.z);
}

Vector3D Vector3D::operator-(const Vector3D &v) const
{
	return Vector3D(x - v.x, y - v.y, z - v.z);
}

Vector3D Vector3D::operator*(const Vector3D &v) const
{
	return Vector3D(x*v.x, y*v.y, z*v.z);
}

Vector3D Vector3D::operator*(float &val) const
{
	return Vector3D(x*val, y*val, z*val);
}


Vector3D Vector3D::operator/(const Vector3D &v) const
{
	return Vector3D(x/v.x, y/v.y, z/v.z);
}

bool Vector3D::operator==(const Vector3D &v) const
{
	if (v.x == x && v.y == y && v.z == z)
		return true;

	return false;
}

Vector3D & Vector3D::operator+=(const Vector3D & v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
	return *this;
}

Vector3D & Vector3D::operator-=(const Vector3D & v)
{
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;
	return *this;
}

Vector3D Vector3D::operator*(const float &val) const
{
	return Vector3D(x*val, y*val, z*val);
}

Vector3D Vector3D::operator/(const float &val) const
{
	return Vector3D(x/val, y/val, z/val);
}

float Vector3D::DotProduct(const Vector3D &v1, const Vector3D &v2)
{
	return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}

bool Vector3D::lies_between(const Vector3D a, const Vector3D b) {
	if (a.x <= x && x <= b.x &&
		a.y <= y && y <= b.y &&
		a.z <= z && z <= b.z)
		return true;
	else return false;
}

float Vector3D::Magnitude(const Vector3D &v)
{
	return float(sqrt(v.x*v.x + v.y*v.y));
}

Vector3D Vector3D::Normal(const Vector3D &v)
{
	float magnitude = Magnitude(v);
	return Vector3D(v.x / magnitude, v.y / magnitude, v.z / magnitude);
}

Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3D Vector3D::Perpendicular(const Vector3D &)
{
	return Vector3D();
}

Vector3D::~Vector3D() {
}
