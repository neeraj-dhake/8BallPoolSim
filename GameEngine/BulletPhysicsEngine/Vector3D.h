#pragma once
#include "../Include/btBulletDynamicsCommon.h"
struct Vector3D {
	float x, y, z;
	Vector3D();
	Vector3D(float,float,float);
	Vector3D(btVector3);

	btVector3 to_btVector3();

	Vector3D &operator=(const Vector3D& v);
	Vector3D operator+(const Vector3D&) const;
	Vector3D operator-(const Vector3D&) const;
	Vector3D operator*(const Vector3D&) const;
	Vector3D operator*(float&   ) const;
	Vector3D operator/(const Vector3D&) const;

	bool operator==(const Vector3D&) const;

	Vector3D &operator+=(const Vector3D& v);
	Vector3D &operator-=(const Vector3D& v);
	Vector3D operator*(const float&) const;
	Vector3D operator/(const float&) const;

	bool lies_between(Vector3D, Vector3D);

	//Product functions
	static float DotProduct(const Vector3D&, const Vector3D&);

	//Returns the length of the vector from the origin.
	static float Magnitude(const Vector3D&);

	//Return the unit vector of the input
	static Vector3D Normal(const Vector3D&);

	//Return a vector perpendicular to the left.
	static Vector3D Perpendicular(const Vector3D&);

	~Vector3D();
};

