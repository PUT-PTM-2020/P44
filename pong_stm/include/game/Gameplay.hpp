#pragma once
#include "SimObject.hpp"
#include "ObjectsVector.hpp"
#include "UpdateObject.hpp"
#include "DrawnObject.hpp"
#include "ge.hpp"
#include "Ball.hpp"
#include "Collision.hpp"
#include "Rect.hpp"
#include "Racket.hpp"
#include "Wall.hpp"
#include "Table.hpp"
#include "he.hpp"


class Gameplay
{
    friend class Collision;
private:
    Wall *wallL,*wallR,*wallD;
    Table *table1,*table2,*net;
    Racket *racket1,*racket2;
    Ball *ball,*ball2;
    static ObjectsVector<SimObject*> simVector;

public:
	static ObjectsVector<SimObject*>& getSimVector();
    static GE::Vector2i default_ballLPos, default_ballRPos, default_racketLPos, default_racketRPos;
	static int player1Score, player2Score;
    static int mode;
    static Collision collision;
	void simulateObjects();
	void simulate();
    Gameplay();
    ~Gameplay();
};