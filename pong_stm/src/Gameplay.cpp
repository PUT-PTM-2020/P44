#include "Gameplay.hpp"
#include "Game.hpp"

ObjectsVector<SimObject*> Gameplay::simVector;
GE::Vector2i Gameplay::default_ballLPos;
GE::Vector2i Gameplay::default_ballRPos;
GE::Vector2i Gameplay::default_racketLPos;
GE::Vector2i Gameplay::default_racketRPos;
//Collision Gameplay::collision;
int Gameplay::player1Score = 0;
int Gameplay::player2Score = 0;
int Gameplay::mode = 0;

ObjectsVector<SimObject*> &Gameplay::getSimVector() {
	return simVector;
}


Gameplay::Gameplay() {
	this->wallD = new Wall(3,479,0,Physics::Materials::wood,0,0,2);
	this->wallL = new Wall(320,2,0,Physics::Materials::wood,0,0,1);
	this->wallR = new Wall(320,4,0,Physics::Materials::wood,479,0,3);

	this->table1 = new Table(10,150,0,Physics::Materials::wood,85,50,1);
	this->table2 = new Table(10,150,0,Physics::Materials::wood,235,50,2);
	this->net = new Table(25,6,0,Physics::Materials::wood,232,60,3);
	this->ball = new Ball(50.0f, 60.0f);
	this->ball->setVelocityVector({ 12.0f, 20.0f });
	this->default_ballLPos = { 200,360 };
	this->default_ballRPos = { 1080,360 };
	this->default_racketLPos = { 150,360 };
	this->default_racketRPos = { 1130,360 };
	this->player1Score = 0;
	this->player2Score = 0;
}

void Gameplay::simulateObjects() {

		for(auto i = this->simVector.get().begin();i!= this->simVector.get().end();i++)
	 {
		GE::Vector2i posBefore = (*i)->getPos();
		GE::Vector2i posAfter = (*i)->getPos();;
		for (int j = 0; j < Game::simPerFrame; j++) (*i)->simulation(&posAfter);
		if(posBefore!=posAfter)(*i)->setPos(Physics::swapY(posAfter));	
			};
}

void Gameplay::simulate() {
	simulateObjects();
	//collision.checkCollisions();
}

Gameplay::~Gameplay() {
	delete ball;
}