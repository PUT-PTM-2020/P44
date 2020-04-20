
#include "Racket.hpp"
#include "Game.hpp"

Racket::Racket(float posX, float posY,bool isAI, int whichPlayer) :
	MovingObject(RACKET_DEFAULT_MASS), 
	Rect(RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y, 0.0f, Physics::Materials::racket, posX, posY,1){
	//Collision::getRacketCollisionVector()._add(this);
	this->isAI = isAI;
	this->whichPlayer = whichPlayer;
	this->oldRealPos = this->realPos;	
}

/*void Racket::rotation() {

		if (GE::Mouse::isButtonPressed(GE::Mouse::Left)) angle -= (150.5f / Game::getSimPerFrame()) * elapsedTime;
		if (GE::Mouse::isButtonPressed(GE::Mouse::Right)) angle += (150.5f / Game::getSimPerFrame()) * elapsedTime;
		if (GE::Mouse::isButtonPressed(GE::Mouse::Middle)) angle = 0.0f;
		if (angle >= 180.0f) angle -= 180.0f;
		if (angle <= -180.0f) angle += 180.0f;
		dObject->setRotation(angle);
}*/

void Racket::update() {

		getSimTime();
		getElapsedTime();
		velocityVector = quickVelocityVector / (float)Game::getSimPerFrame();
		quickVelocityVector = { 0.0f, 0.0f };

		velocity = calcVelocityFromVelocityVector(velocityVector);
		if (velocity != 0.0f) {
			unitVector = calcUnitVector(velocityVector, velocity);
		}
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

	if (!isAI)
	{
		quickVelocityVector += calcVelocityVector(oldRealPos, realPos, simTime);
		*pos = Physics::floatVectorToIntVector(Physics::calcPixelVector(realPos));
		oldRealPos = realPos;
	}
	
}

Racket::~Racket() {
	//Collision::getRacketCollisionVector()._delete(this);
}

void Racket::test() {
	
}
