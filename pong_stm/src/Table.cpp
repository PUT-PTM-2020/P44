#include "Table.hpp"
#include "Game.hpp"



Table::Table(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY, int player):
	Rect(pixelSizeX, pixelSizeY, angle,  material, pixelPosX, pixelPosY,0)
{
	this->player = player;
	//Collision::getTableCollisionVector()._add(this);
	if (player == 1)
	{
		dObject->setColor(GE::Color::white);
	}
	else dObject->setColor(GE::Color::green);
}

Table::~Table()
{
	//Collision::getTableCollisionVector()._delete(this);
}