#pragma once

#include "DrawnObject.hpp"
#include "PhysicalObject.hpp"

class Rect : public DrawnObject<GE::Rect>, public PhysicalObject {
	friend class Collision;
protected:
	float realLength, realWidth, angle, pixelRadius;
	GE::Vector2f localSP, localEP;

public:
	Rect(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosYi,int which);
	virtual ~Rect();
};

