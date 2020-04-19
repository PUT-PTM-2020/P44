#include "Physics.hpp"

const float Physics::pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
float Physics::viscosity = PHYSICS_DEFAULT_VISCOSITY;
float Physics::grav = PHYSICS_DEFAULT_GRAV;
float Physics::wind = -4.0f;

const Physics::Material Physics::Materials::wood = { 1.0f, 1.0f };
const Physics::Material Physics::Materials::ball = { 1.0f, 1.0f };
const Physics::Material Physics::Materials::racket = { 1.0f, 1.0f };
const Physics::Material Physics::Materials::net = { 0.2f, 0.2f };

void Physics::resetValues() {
	viscosity = PHYSICS_DEFAULT_VISCOSITY;
	grav = PHYSICS_DEFAULT_GRAV;
	wind = 0.0f;
}

GE::Vector2i Physics::floatVectorToIntVector(const GE::Vector2f &floatVector) {
	return { (int)floatVector.x, (int)floatVector.y };
}

GE::Vector2f Physics::calcRealVector(const GE::Vector2f &pixelVector) {
	float ptrr = pixelToRealRatio;
	return { pixelVector.x * ptrr, pixelVector.y * ptrr };
}

//Przeciążenie, aby działało też dla wektorów intowych
GE::Vector2f Physics::calcRealVector(const GE::Vector2i &pixelVector) {
	float ptrr = pixelToRealRatio;
	return { (float)pixelVector.x * ptrr, (float)pixelVector.y * ptrr };
}

GE::Vector2f Physics::calcPixelVector(const GE::Vector2f &realVector) {
	float ptrr = pixelToRealRatio;
	return { (float)realVector.x / ptrr, (float)realVector.y / ptrr };
}

float Physics::calcRealValue(const float &pixelValue) {
	return pixelValue * pixelToRealRatio;
}

int Physics::calcPixelValue(const float &realValue) {
	return realValue / pixelToRealRatio;
}

GE::Vector2i Physics::swapY(const GE::Vector2i &pos) {
	return { (int)pos.y, (int)pos.x };
}

float Physics::calcDistanceBetweenTwoPoints(const GE::Vector2f &v1, const GE::Vector2f &v2) {
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
}

float Physics::calcDirectionFactor(float x1, float y1, float x2, float y2)
{
	return (y2 - y1) / (x2 - x1);
}