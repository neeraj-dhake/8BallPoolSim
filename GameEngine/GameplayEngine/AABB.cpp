#include "AABB.h"
#include <vector>

Vector3D GetIntersection_Ray_Plane(Vector3D _ray, Vector3D _plane) {
	float cos_theta = Vector3D::DotProduct(_ray, _plane) / Vector3D::Magnitude(_plane);
	return _ray * Vector3D::Magnitude(_plane) / cos_theta;
}

float AABB::GetNearestDistance(Vector3D* _ray) const{
	std::vector<Vector3D> planes;
	planes.reserve(6);
	planes.push_back(Vector3D(dimensions.x/2, 0, 0));
	planes.push_back(Vector3D(-dimensions.x/2, 0, 0));
	planes.push_back(Vector3D(0, dimensions.y/2, 0));
	planes.push_back(Vector3D(0, -dimensions.y/2, 0));
	planes.push_back(Vector3D(0, 0, dimensions.z/2));
	planes.push_back(Vector3D(0, 0, -dimensions.z/2));
	Vector3D current;
	for (int i = 0; i < 6; i++) {
		current = GetIntersection_Ray_Plane(*_ray, planes[i]);
		if (Vector3D::DotProduct(current, *_ray) > 0 && current.lies_between(dimensions / (-2), dimensions / 2)) {
			break;
		}
	}
	return Vector3D::Magnitude(current);
}