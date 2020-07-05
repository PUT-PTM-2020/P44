
#include "Racket.hpp"
#include "Game.hpp"

Racket::Racket(float posX, float posY,bool isAI, int whichPlayer) :
	MovingObject(RACKET_DEFAULT_MASS), 
	Rect(RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y, 0.0f, Physics::Materials::racket, posX, posY,1){
	Collision::getRacketCollisionVector()._add(this);
	this->isAI = isAI;
	this->whichPlayer = whichPlayer;
	this->oldRealPos = this->realPos;
	this->prev_acc = {0,0};
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

if(whichPlayer == 1)
{
	if(Game::radioResponse.startContr1)
	{
		checkAcc1 = 0;
		if(giveVec)
		{
			float prop = (pos->x - Gameplay::default_ballLPos.x) / (pos->y - Gameplay::default_ballLPos.y);
			float y = 2/(prop + 1);
			float x = prop * y;
			if(pos->y > Gameplay::default_ballLPos.y) y = -y;
			if(pos->x > Gameplay::default_ballLPos.x) x = -x;
			quickVelocityVector = {x,y};
			giveVec = !giveVec;
		}
		if(pos->x <= Gameplay::default_racketLPos.x + 5 && pos->x >= Gameplay::default_racketLPos.x - 5)
		quickVelocityVector = {0,0};		
	}
	else 
	{
		checkAcc1 = 1;
		giveVec = 1;
	}

	if(abs(Game::radioResponse.accContr1.x - prev_acc.x) > 20.0f && checkAcc1)
	{
		Game::radioResponse.accContr1 = {0.0f,Game::radioResponse.accContr1.y};
		quickVelocityVector = {0.0f,quickVelocityVector.y};
	}

	if(abs(Game::radioResponse.accContr1.y - prev_acc.y) > 20.0f && checkAcc1)
	{
		Game::radioResponse.accContr1 = {Game::radioResponse.accContr1.x,0.0f};
		quickVelocityVector = {quickVelocityVector.x,0.0f};
	}
	if(checkAcc1)
	{
		quickVelocityVector += (Game::radioResponse.accContr1 * simTime);
		prev_acc = Game::radioResponse.accContr1;
	}
	if(abs(Game::radioResponse.accContr1.x) < 0.5f && checkAcc1)
	{
			accTrl1++;
	}
	else accTrl1 = 0;
	if(accTrl1 == 10)
	{
			quickVelocityVector = {0.0f,0.0f};
			accTrl1=0;
	}
}
else
{
	if(Game::radioResponse.startContr1)
	{
		checkAcc1 = 0;
		if(giveVec)
		{
			float prop = (pos->x - Gameplay::default_ballRPos.x) / (pos->y - Gameplay::default_ballRPos.y);
			float y = 2/(prop + 1);
			float x = prop * y;
			if(pos->y > Gameplay::default_ballLPos.y) y = -y;
			if(pos->x > Gameplay::default_ballLPos.x) x = -x;
			quickVelocityVector = {x,y};
			giveVec = !giveVec;
		}
		if(pos->x <= Gameplay::default_racketLPos.x + 5 && pos->x >= Gameplay::default_racketLPos.x - 5)
		quickVelocityVector = {0,0};
	}
	else 
	{
		checkAcc2 = 1;
	}

	if(abs(Game::radioResponse.accContr2.x - prev_acc.x) > 3.0f && checkAcc2)
	{
		Game::radioResponse.accContr2 = {0.0f,Game::radioResponse.accContr2.y};
		quickVelocityVector = {0.0f,quickVelocityVector.y};
	}

	if(abs(Game::radioResponse.accContr2.y - prev_acc.y) > 3.0f&& checkAcc2)
	{
		Game::radioResponse.accContr2 = {Game::radioResponse.accContr2.x,0.0f};
		quickVelocityVector = {quickVelocityVector.x,0.0f};
	}
	if(checkAcc2)
	{
		quickVelocityVector += (Game::radioResponse.accContr2 * simTime);
		prev_acc = Game::radioResponse.accContr2;
	}
	if(abs(Game::radioResponse.accContr2.x) < 0.5f && checkAcc2)
	{
			accTrl2++;
	}
	else accTrl2 = 0;
	if(accTrl2 == 10)
	{
			quickVelocityVector = {0.0f, 0.0f};
			accTrl2=0;
	}
		
}
realPos += (simTime * quickVelocityVector);
*pos = Physics::floatVectorToIntVector(Physics::calcPixelVector(realPos));
}

Racket::~Racket() {
	//Collision::getRacketCollisionVector()._delete(this);
}

