
#include "Racket.hpp"
#include "Game.hpp"

Racket::Racket(float posX, float posY,bool isAI, int whichPlayer) :
	MovingObject(RACKET_DEFAULT_MASS), 
	Rect(RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y, 0.0f, Physics::Materials::racket, posX, posY,1){
	Collision::getRacketCollisionVector()._add(this);
	this->isAI = isAI;
	this->whichPlayer = whichPlayer;
	this->oldRealPos = this->realPos;
}



void Racket::update() {
		getSimTime();
}


void Racket::setPos(GE::Vector2i pos)
{
	this->dObject->setPos(pos);
	pos = Physics::swapYR(pos);
	localEP = { (dObject->getSizeX() / 2) + pos.x, pos.y};
	localSP = { (dObject->getSizeX() / 2) + pos.x, pos.y - dObject->getSizeY()};
	
}

GE::Vector2i Racket::getPos()
{
	return dObject->getPos();
}

void Racket::simulation(GE::Vector2i* pos) {

if(Game::radioResponse.accContr1.x > 5 || Game::radioResponse.accContr1.y > 5)
{
	Game::radioResponse.accContr1 = {0,0};
	quickVelocityVector = {0,0};
}
if(Game::radioResponse.accContr2.x > 5 || Game::radioResponse.accContr2.y > 5)
{
	Game::radioResponse.accContr2 = {0,0};
	quickVelocityVector = {0,0};
}

		if(whichPlayer == 1)
		{
			quickVelocityVector += (Game::radioResponse.accContr1 * simTime);
		}
		else
		{
			quickVelocityVector += (Game::radioResponse.accContr2 * simTime);
		}
		if(Game::radioResponse.accContr1.x == 0)
		{
			accTrl1++;
		}
		else if(Game::radioResponse.accContr2.x == 0)
		{
			accTrl2++;
		}
		else 
		{
			accTrl2=0;
			accTrl1=0;
		}

		if(accTrl2 == 100)
		{
			quickVelocityVector = {0,0};
			accTrl2 = 0;
		}
		if(accTrl1 == 100)
		{
			quickVelocityVector = {0,0};
			accTrl1=0;
		}
		realPos += (simTime * quickVelocityVector);
		*pos = Physics::floatVectorToIntVector(Physics::calcPixelVector(realPos));

}

Racket::~Racket() {
	//Collision::getRacketCollisionVector()._delete(this);
}

