#include "Game.hpp"

ObjectsVector<UpdateObject*> Game::updateVector;
ObjectsVector<GE::Shape*> Game::drawVector;
ObjectsVector<GE::Shape*> Game::drawOnce;
const int Game::simPerFrame = 10;
float Game::lastTime = 0.0f;
float Game::timeForBall = 0.0f;
float Game::elapsedTime = Game::getTime();
float Game::simTime = Game::elapsedTime / (float)Game::simPerFrame;
bool Game::reset_ball = false;
bool Game::buttonPress = false;
bool Game::oledChange = true;
Gameplay *Game::gameplay;
HE::Clock Game::clock;
HE::Clock Game::clock1;
HE::Clock Game::frameClock;
HE::Radio::Response Game::radioResponse;

Game::Game(HE::Oled* oled, HE::Radio* radio)
{
	this->oled = oled;
	this->radio = radio;
	this->gameplay = new Gameplay();
	for(auto i = drawOnce.get().begin();i!= drawOnce.get().end();i++)
	{
		(*i)->draw();
	}

}

ObjectsVector<UpdateObject*> &Game::getUpdateVector() {
	return updateVector;
}

ObjectsVector<GE::Shape*> &Game::getDrawVector() {
	return drawVector;
}

ObjectsVector<GE::Shape*> &Game::getDrawOnce()
{
	return drawOnce;
}

int Game::getSimPerFrame() {
	return simPerFrame;
}

float Game::getSimTime() {
	return simTime;
}
float Game::getTime() {
	return clock.getTime();
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
		if((*i)->getPos().y < 340)
		(*i)->draw();
	}

}

void Game::updateObjects() {
	updateVector.forEach([](UpdateObject* &obj) {
		obj->update();
	});
}

void Game::calcTimes() {
	//elapsedTime = Game::getTime() - lastTime;
	//lastTime = Game::getTime();
	//simTime = elapsedTime / (float)simPerFrame;
	simTime = (1.0f/(60*simPerFrame));
	lastTime = (simTime*simPerFrame) + lastTime;
}

void Game::checkButtons() {
	if (HE::Buttons::statusWindPlus()) {
		Physics::wind += 0.01f;
		Game::oledChange = true;
	}
	if (HE::Buttons::statusWindMinus()) {
		Physics::wind -= 0.01f;
		Game::oledChange = true;
	}
	if (HE::Buttons::statusGravPlus()) {
		Physics::grav += 0.02f;
		Game::oledChange = true;
	}
	if (HE::Buttons::statusGravMinus()) {
		Physics::grav -= 0.02f;
		Game::oledChange = true;
	}
	if (HE::Buttons::statusAirDensPlus()) {
		Physics::viscosity += 0.005f;
		Game::oledChange = true;
	}
	if (HE::Buttons::statusAirDensMinus()) {
		Physics::viscosity -= 0.005f;
		Game::oledChange = true;
	}
	if (HE::Buttons::statusReset()) {
		Physics::wind = 0.0f;
		Physics::grav = PHYSICS_DEFAULT_GRAV;
		Physics::viscosity = PHYSICS_DEFAULT_VISCOSITY;
		Game::oledChange = true;
	}

}

void Game::displayOled() {
	if (this->oledChange) {
		char stringBuf[64];
		sprintf(stringBuf, "Wiatr: %f", Physics::wind);
		this->oled->writeLine(0, stringBuf);
		sprintf(stringBuf, "Graw.: %f", Physics::grav);
		this->oled->writeLine(1, stringBuf);
		sprintf(stringBuf, "Opor.: %f", Physics::viscosity);
		this->oled->writeLine(2, stringBuf);
		sprintf(stringBuf, "Wynik:");
		this->oled->writeLine(3, stringBuf);
		this->oled->display();
		Game::oledChange = false;
	}
}

void Game::checkRadio() {
	Game::radioResponse.accContr1 =  {0.8f,0.0f};
	Game::radioResponse.startContr1 = false;
}

void Game::manageEvents()//podrzucanie pileczki
{
	checkButtons();
	displayOled();
	checkRadio();
}

void Game::run() {

		manageEvents();
		calcTimes();//Funkcja obliczająca czas jaki upłynął między obecną klatką a poprzednią
		updateObjects();//Funkcja updateujaca wartosci czasowe
		gameplay->simulate();//Funkcja służąca do obliczania głównie nowego położenia obiektów poruszających się
		drawObjects();//Funkcja rysująca obiekty znajdujące się w drawVector
		frameClock.reset();

}