#pragma once
#include "Rect.hpp"
#include "Game.hpp"
#include "Physics.hpp"

Rect::Rect(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY,int which) :
	DrawnObject(new GE::Rect(pixelSizeX,pixelSizeY,pixelPosY,pixelPosX,GE::Color::white),which),
	PhysicalObject (material, pixelPosX, pixelPosY) {
	this->realLength = Physics::calcRealValue(pixelSizeY);
	this->realWidth = Physics::calcRealValue(pixelSizeX);
	this->angle = angle;
	if (pixelSizeX <= pixelSizeY) this->localSP = { pixelSizeX / 2.0f, 0.0f };
	else this->localSP = { 0.0f, pixelSizeY / 2.0f };
	if (pixelSizeX <= pixelSizeY) this->localEP = { pixelSizeX / 2.0f, pixelSizeY };
	else this->localEP = { pixelSizeX, pixelSizeY / 2.0f };
	if (pixelSizeX <= pixelSizeY) this->pixelRadius = pixelSizeX / 2.0f;
	else this->pixelRadius = pixelSizeY / 2.0f;
}

Rect::~Rect() {
	
}
