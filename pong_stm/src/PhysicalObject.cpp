#include "PhysicalObject.hpp"
#include "Game.hpp"

PhysicalObject::PhysicalObject(Physics::Material material, float pixelPosX, float pixelPosY) {
	this->material = material;
	this->realPos = Physics::calcRealVector(GE::Vector2f(pixelPosX, pixelPosY));
}



