#include "MovingObject.hpp"



MovingObject::MovingObject(float mass) : 
	UpdateObject(),
	SimObject() {
	this->mass = mass;
	this->velocityVector = { 0.0f, 0.0f };
	this->velocity = 0.0f;
}

//*****PROTECTED*****

GE::Vector2f MovingObject::calcVelocityVector(const GE::Vector2f &lastRealPos, const GE::Vector2f &newRealPos, const float &time) {
	return (newRealPos - lastRealPos) / time;
}

float MovingObject::calcVelocityFromVelocityVector(const GE::Vector2f &velocityVector) {
	return sqrt(pow((velocityVector.x), 2) + pow((velocityVector.y), 2));
}

GE::Vector2f MovingObject::calcUnitVector(const GE::Vector2f &velocityVector, const float &velocity) {
	return velocityVector / velocity;
}

float MovingObject::calcKineticEnergy(const float &mass, const float &velocity) {
	return (mass * (velocity * velocity)) / 2.0f;
}

//*****PUBLIC*****

void MovingObject::setMass(const float &m) {
	mass = m;
}

void MovingObject::setVelocityVector(const GE::Vector2f &vV) {
	velocityVector = vV;
	velocity = calcVelocityFromVelocityVector(velocityVector);
}

void MovingObject::setOldRealPos(const GE::Vector2f &oRP) {
	oldRealPos = oRP;
}