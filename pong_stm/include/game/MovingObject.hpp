#pragma once

#include "DrawnObject.hpp"
#include "UpdateObject.hpp"
#include "SimObject.hpp"
#include "Physics.hpp"

class MovingObject : public UpdateObject, public SimObject {
protected:
	float mass, velocity, kineticEnergy;
	GE::Vector2f oldRealPos, velocityVector, unitVector;
	GE::Vector2f calcVelocityVector(const GE::Vector2f &lastRealPos, const GE::Vector2f &newRealPos, const float &t);
	float calcVelocityFromVelocityVector(const GE::Vector2f &velocityVector);
	GE::Vector2f calcUnitVector(const GE::Vector2f &velocityVector, const float &velocity);
	float calcKineticEnergy(const float &mass, const float &velocity);
public:
	MovingObject(float mass);
	void setMass(const float &mass);
	void setVelocityVector(const GE::Vector2f &velocityVector);
	void setOldRealPos(const GE::Vector2f &oRP);
};

