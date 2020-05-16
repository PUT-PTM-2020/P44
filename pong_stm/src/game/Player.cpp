
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
