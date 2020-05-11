
#include "Racket.hpp"
#include "Game.hpp"

Racket::Racket(float posX, float posY,bool isAI, int whichPlayer) :
	MovingObject(RACKET_DEFAULT_MASS), 
	Rect(RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y, 0.0f, Physics::Materials::racket, posX, posY,1){
	Collision::getRacketCollisionVector()._add(this);
	this->isAI = isAI;
	this->whichPlayer = whichPlayer;
	this->oldRealPos = this->realPos;
	this->dObject->setColor(GE::Color::white);	
}



void Racket::update() {
		getSimTime();
}


void Racket::setPos(GE::Vector2i pos)
{
	pos = (Physics::swapY({(float)pos.x,(float)pos.y}));
	this->dObject->setPos(pos);
}

GE::Vector2i Racket::getPos()
{
	return dObject->getPos();
}

void Racket::simulation(GE::Vector2i* pos) {

	
	if (realPos != oldRealPos) {
		if ((realPos.x - oldRealPos.x) > (RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.x = oldRealPos.x + (RACKET_DEFAULT_MAX_VELOCITY * simTime);
		if ((realPos.x - oldRealPos.x) < (-RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.x = oldRealPos.x - (RACKET_DEFAULT_MAX_VELOCITY * simTime);
		if ((realPos.y - oldRealPos.y) > (RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.y = oldRealPos.y + (RACKET_DEFAULT_MAX_VELOCITY * simTime);
		if ((realPos.y - oldRealPos.y) < (-RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.y = oldRealPos.y - (RACKET_DEFAULT_MAX_VELOCITY * simTime);
	}
		if(whichPlayer == 1)
		{
			quickVelocityVector += (Game::radioResponse.accContr1 * simTime);
		}
		else
		{
			quickVelocityVector += (Game::radioResponse.accContr2 * simTime);
		}
		realPos +=(quickVelocityVector * simTime);
		*pos = Physics::floatVectorToIntVector(Physics::calcPixelVector(realPos));

}

Racket::~Racket() {
	//Collision::getRacketCollisionVector()._delete(this);
}

