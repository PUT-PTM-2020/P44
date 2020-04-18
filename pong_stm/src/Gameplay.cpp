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
	
	this->ball = new Ball(200.0f, 300.0f);
	this->ball->setVelocityVector({ 0.0f, 0.0f });
	
	this->default_ballLPos = { 200,360 };
	this->default_ballRPos = { 1080,360 };
	this->default_racketLPos = { 150,360 };
	this->default_racketRPos = { 1130,360 };
	this->player1Score = 0;
	this->player2Score = 0;
}

void Gameplay::simulateObjects() {
	simVector.forEach([](SimObject* &obj) {
		obj->simulation();
	});
}

void Gameplay::simulate() {
	simulateObjects();
	//collision.checkCollisions();
}

Gameplay::~Gameplay() {
	delete ball;
}