#pragma once

#include "Physics.hpp"
class PhysicalObject {
protected:
	Physics::Material material;
	GE::Vector2f realPos;

public:
	PhysicalObject(Physics::Material material, float pixelPosX, float pixelPosY);
};