#pragma once
#include "Rect.hpp"
#include "MovingObject.hpp"

#define RACKET_DEFAULT_MASS 0.160f
#define RACKET_DEFAULT_PIXEL_SIZE_X 5.0f
#define RACKET_DEFAULT_PIXEL_SIZE_Y 70.0f
#define RACKET_DEFAULT_MAX_VELOCITY 15.0f

class Racket : public MovingObject, public Rect {
	friend class Collision;
	friend class Player;
private:
	GE::Vector2f quickVelocityVector;
	bool isAI;
	int whichPlayer;
public:
	Racket(float posX, float posY,bool isAI, int whichPlayer);
	void rotation();
	void update();
	void simulation();
	~Racket();
	void test();
};

