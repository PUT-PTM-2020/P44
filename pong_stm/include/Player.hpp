#pragma once

#include "Racket.hpp"
#include "Table.hpp"
#include "Ball.hpp"
class Player : public SimObject {
	friend class Collision;
private:
	int mode;
	Racket* racket;
	Table* table;
	Ball* ball;
	int points;
	float licz;
	float pom;
	int playerNumber;
	static bool TPMousePlayer1, TPMousePlayer2;
public:
	Player(int mode, Racket* racket, Table* table, Ball* ball, int playerNumber);
	void move();
	void setPoints(int points);
	int getPoints();
	void simulation();
	~Player();
};

