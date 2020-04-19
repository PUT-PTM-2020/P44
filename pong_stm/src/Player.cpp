
#include "Player.hpp"
#include "Game.hpp"

bool Player::TPMousePlayer1 = false;
bool Player::TPMousePlayer2 = false;

Player::Player(int mode, Racket* racket, Table* table,Ball* ball, int playerNumber) {
	this->mode = mode;
	this->racket = racket;
	this->table = table;
	this->points = 0;
	this->ball = ball;
	this->playerNumber = playerNumber;
	licz = 0;
	this->TPMousePlayer1 = false;
	this->TPMousePlayer2 = false;
}

void Player::move() {

		
		if (playerNumber == 1) {
			if (ball->p1Serv == 2 || Collision::who == 2) {
				if (TPMousePlayer1) {
					//sf::Mouse::setPosition(racket->windowObj.mapCoordsToPixel(racket->dObject->getPosition()), racket->windowObj);
					TPMousePlayer1 = false;
					
				}
				//racket->rotation();
				//racket->realPos = Physics::swapY(Physics::calcRealVector(racket->windowObj.mapPixelToCoords(sf::Mouse::getPosition(racket->windowObj))));
				TPMousePlayer2 = true;
			}

		} else if (playerNumber == 2) {
			if (ball->p2Serv == 2 || Collision::who == 1) {
				if (TPMousePlayer2) {
					//sf::Mouse::setPosition(racket->windowObj.mapCoordsToPixel(racket->dObject->getPosition()), racket->windowObj);
					TPMousePlayer2 = false;
					
				}
				//racket->rotation();
				//racket->realPos = Physics::swapY(Physics::calcRealVector(racket->windowObj.mapPixelToCoords(sf::Mouse::getPosition(racket->windowObj))));
				TPMousePlayer1 = true;
			}
		} 
			
			racket->realPos = { Physics::calcRealValue(racket->dObject->getPosX()),
			Physics::calcRealValue(racket->dObject->getPosY())};
			
}	

void Player::setPoints(int points) {
	this->points = points;
}

int Player::getPoints() {
	return points;
}

void Player::simulation() {
	move();
}

Player::~Player() {
	licz = 0;
}
