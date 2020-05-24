#pragma once
#include "Rect.hpp"
#include "MovingObject.hpp"

#define RACKET_DEFAULT_MASS 0.160f
#define RACKET_DEFAULT_PIXEL_SIZE_X 5.0f
#define RACKET_DEFAULT_PIXEL_SIZE_Y 40.0f
#define RACKET_DEFAULT_MAX_VELOCITY 15.0f

class Racket : public MovingObject, public Rect {
	friend class Collision;
	friend class Player;
private:
	GE::Vector2f quickVelocityVector;
	bool isAI;
	int whichPlayer;
	int accTrl1,accTrl2;
	GE::Vector2f prev_acc;
public:
	Racket(float posX, float posY,bool isAI, int whichPlayer);
	void setPos(GE::Vector2i pos);
	GE::Vector2i getPos();
	void update();
	void simulation(GE::Vector2i* pos);
	~Racket();
};

