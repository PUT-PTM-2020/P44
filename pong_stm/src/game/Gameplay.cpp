#include "Gameplay.hpp"
#include "Game.hpp"

ObjectsVector<SimObject*> Gameplay::simVector;
GE::Vector2i Gameplay::default_ballLPos;
GE::Vector2i Gameplay::default_ballRPos;
GE::Vector2i Gameplay::default_racketLPos;
GE::Vector2i Gameplay::default_racketRPos;
Collision Gameplay::collision;
int Gameplay::player1Score = 0;
int Gameplay::player2Score = 0;
int Gameplay::mode = 0;

ObjectsVector<SimObject*> &Gameplay::getSimVector() {
	return simVector;
}


Gameplay::Gameplay() {

	this->default_ballLPos = { 70, 140 };
	this->default_ballRPos = { 410, 140 };
	this->default_racketLPos = { 20, 150 };
	this->default_racketRPos = { 460, 150 };

	this->wallD = new Wall(479,3,0,Physics::Materials::wood,0,0,2);
	this->wallL = new Wall(2,700,0,Physics::Materials::wood,0,0,1);
	this->wallR = new Wall(2,700,0,Physics::Materials::wood,479,0,3);

	this->table1 = new Table(150,10,0,Physics::Materials::wood,235,50,1);
	this->table2 = new Table(150,10,0,Physics::Materials::wood,385,50,2);
	this->net = new Table(6,25,0,Physics::Materials::wood,237,65,3);

	this->racket1 = new Racket(default_racketLPos.x,default_racketLPos.y,0,1);
	this->racket2 = new Racket(default_racketRPos.x,default_racketRPos.y,0,2);

	this->ball = new Ball((float)this->default_ballLPos.x, (float)this->default_ballLPos.y);
	this->ball->setVelocityVector({ 0.0f, 0.0f });

	this->player1Score = 0;
	this->player2Score = 0;
}

void Gameplay::simulateObjects() {

		for(auto i = this->simVector.get().begin();i!= this->simVector.get().end();i++)
	 	{
			GE::Vector2i posBefore = (*i)->getPos();
			GE::Vector2i posAfter = (*i)->getPos();
			for (int j = 0; j < Game::simPerFrame; j++) (*i)->simulation(&posAfter);
			if(posBefore!=posAfter)(*i)->setPos(Physics::swapY(posAfter));	
		};
}

void Gameplay::simulate() {
	simulateObjects();
	collision.checkCollisions();
}

Gameplay::~Gameplay() {
	delete ball;
}