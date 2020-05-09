#include "Wall.hpp"
#include "Game.hpp"

Wall::Wall(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY,int which_wall) :
	Rect(pixelSizeX, pixelSizeY, angle, material, pixelPosX, pixelPosY,0) {
	Collision::getWallCollisionVector()._add(this);
	this->which_wall = which_wall;
	dObject->setColor(GE::Color::black);
};


Wall::~Wall() {
	//Collision::getWallCollisionVector()._delete(this);
}
