#pragma once
#include "Rect.hpp"

class Table : public Rect
{
	friend class Collision;

private:
	int player; // 1 player nr1   2 player nr2
public:
	Table(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY, int player);
	~Table();
};