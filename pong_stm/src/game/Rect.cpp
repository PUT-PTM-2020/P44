#include "Rect.hpp"
#include "Game.hpp"
#include "Physics.hpp"

bool Rect::has_collision = false;

Rect::Rect(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY,int which) :
	DrawnObject(new GE::Rect(pixelSizeY,pixelSizeX,320-pixelPosY,480-pixelPosX,GE::Color::white),which),
	PhysicalObject (material, pixelPosX, pixelPosY) {
	this->realLength = Physics::calcRealValue(pixelSizeY);
	this->realWidth = Physics::calcRealValue(pixelSizeX);
	this->angle = angle;

	if (pixelSizeX <= pixelSizeY) this->localSP = { (pixelSizeX / 2) + pixelPosX, pixelPosY };
	else this->localSP = { pixelPosX, (pixelSizeY / 2) + pixelPosY};
	if (pixelSizeX <= pixelSizeY) this->localEP = { (pixelSizeX / 2) + pixelPosX, pixelPosY +pixelSizeY };
	else this->localEP = { pixelPosX + pixelSizeX, (pixelSizeY / 2) + pixelPosY };

}

Rect::~Rect() {
	
}
