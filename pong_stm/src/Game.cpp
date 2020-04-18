#include "Game.hpp"

ObjectsVector<UpdateObject*> Game::updateVector;
ObjectsVector<GE::Shape*> Game::drawVector;
const int Game::simPerFrame = 15;
float Game::lastTime = 0.0f;
float Game::timeForBall = 0.0f;
float Game::elapsedTime = Game::getTime();
float Game::simTime = Game::elapsedTime / (float)Game::simPerFrame;
bool Game::reset_ball = false;
bool Game::buttonPress = false;
Gameplay *Game::gameplay;

ObjectsVector<UpdateObject*> &Game::getUpdateVector() {
	return updateVector;
}

ObjectsVector<GE::Shape*> &Game::getDrawVector() {
	return drawVector;
}

int Game::getSimPerFrame() {
	return simPerFrame;
}

float Game::getSimTime() {
	return simTime;
}
float Game::getTime() {
	
}

float Game::getElapsedTime() {
	return elapsedTime;
}

float Game::getTimeForBall()
{
	return timeForBall;
}

void Game::drawObjects() {
	for(auto i = drawVector.get().begin();i!= drawVector.get().end();i++)
	{
		(*i)->draw();
	}

}

void Game::calcTimes() {
	elapsedTime = Game::getTime() - lastTime;
	lastTime = Game::getTime();
	simTime = elapsedTime / (float)simPerFrame;
}

void Game::manageEvents()//podrzucanie pileczki
{

}

void Game::run() {

		manageEvents();
		calcTimes();
		updateObjects();
		for (int i = 0; i < simPerFrame; i++) gameplay->simulate();
		drawObjects();
		//frameClock.restart();

}