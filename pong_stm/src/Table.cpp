#include "Table.hpp"
#include "Game.hpp"



Table::Table(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY, int player):
	Rect(pixelSizeX, pixelSizeY, angle,  material, pixelPosX, pixelPosY)
{
	this->player = player;
	Collision::getTableCollisionVector()._add(this);
	if (player == 1 || player == 2)
	{
		dObject->setColor(GE::Color::black);
	}
}

Table::~Table()
{
	Collision::getTableCollisionVector()._delete(this);
}