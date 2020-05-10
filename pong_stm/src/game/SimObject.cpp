#include "SimObject.hpp"
#include "Game.hpp"

SimObject::SimObject() {
	sendSimObject();
	this->simPerFrame = Game::getSimPerFrame();
}

void SimObject::getSimTime() {
	simTime = Game::getSimTime();
}

void SimObject::sendSimObject() {
	Gameplay::getSimVector()._add(this);
}

void SimObject::deleteSimObject() {
	Gameplay::getSimVector()._delete(this);
}

SimObject::~SimObject() {
	deleteSimObject();
}