#pragma once

#include "Racket.hpp"
#include "Ball.hpp"
#include "Wall.hpp"
#include "Table.hpp"
#include "ObjectsVector.hpp"
#include "Player.hpp"


class Collision {
private:
	static ObjectsVector<Wall*> walls;
	static ObjectsVector<Racket*> rackets;
	static ObjectsVector<Ball*> balls;
	static ObjectsVector<Table*> tables;
	GE::Vector2f BallVelocityAfterColision;
	unsigned short ballRectCheck(Ball *ball, Rect *rect);
	void ballWallCol(Ball *ball, Wall *wall);
	void ballRacketCol(Ball *ball, Racket *racket);
	void ballTableCol(Ball *ball, Table *table);
	void calcballRacketCol(Ball *ball, Racket *racket);
	void calcballTableCol(Ball *ball, Table *table);
	void p1Point(Ball *ball,Player *p);
	void p2Point(Ball *ball,Player *p);

	bool col_for_wal = false;
	int colision_counter = 0;

	float hitTime = 0.016;
	bool can_hit = true;



public:
	static int who; // Kto odbil 1-gracz pierwszy, 2- gracz drugi
	Player *p1, *p2;
	static ObjectsVector<Wall*> &getWallCollisionVector();
	static ObjectsVector<Racket*> &getRacketCollisionVector();
	static ObjectsVector<Ball*> &getBallCollisionVector();
	static ObjectsVector<Table*> &getTableCollisionVector();
	static bool was_col;
	void checkCollisions();
	~Collision();
};

