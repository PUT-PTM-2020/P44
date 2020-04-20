#pragma once
#include "Rect.hpp"

class Wall : public Rect {

	friend class Collision;
private:
	int which_wall;
public:
	Wall(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY,int which_wall);
	~Wall();
};

