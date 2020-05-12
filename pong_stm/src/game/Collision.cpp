
#include "Collision.hpp"
#include "Game.hpp"
#include <cmath>

ObjectsVector<Wall*> Collision::walls;
ObjectsVector<Racket*> Collision::rackets;
ObjectsVector<Ball*> Collision::balls;
ObjectsVector<Table*> Collision::tables;
bool Collision::was_col = false;//0 nie bylo ani kolizji, 1- pierwsza kolizja, 2-kolejne kolizje nie brane pod uwage ale trzeba rysowac

int Collision::who = 0;

ObjectsVector<Table*> &Collision::getTableCollisionVector()
{
	return tables;
}

ObjectsVector<Wall*> &Collision::getWallCollisionVector() {
	return walls;
}

ObjectsVector<Racket*> &Collision::getRacketCollisionVector() {
	return rackets;
}

ObjectsVector<Ball*> &Collision::getBallCollisionVector() {
	return balls;
}

void Collision::checkCollisions() {

	//Balls and walls
	balls.forEach([this](Ball *ball) {
		walls.forEach([this, ball](Wall *wall) {
			ballWallCol(ball, wall);
		});
	});

	//Balls and rackets
	balls.forEach([this](Ball *ball) {
		rackets.forEach([this, ball](Racket *racket) {
			ballRacketCol(ball, racket);
		});
	});

	//Balls and tables
	balls.forEach([this](Ball *ball) {
		tables.forEach([this, ball](Table *table) {
			ballTableCol(ball, table);
		});
	});
}

void Collision::ballWallCol(Ball *ball, Wall *wall)
{
	unsigned short res = ballRectCheck(ball,wall);
	if(res == 1 && !col_for_wal)
	{
		if (wall->which_wall == 1 || wall->which_wall == 3)
		{
			ball->velocityVector.x = -ball->velocityVector.x;
			col_for_wal = true;
	    }
		else if (wall->which_wall == 2)
		{
			ball->velocityVector.y = -ball->velocityVector.y*0.95;
			col_for_wal = true;
		}
	}
	else
	{
		colision_counter++;
		if(colision_counter > 8) 
		{
			colision_counter = 0;
			col_for_wal = false;
		}
	}
	
	return;
}

void Collision::ballTableCol(Ball *ball, Table *table)
{
	unsigned short res = ballRectCheck(ball,table);
	if(res == 1 && !was_col)
	{
		calcballTableCol(ball,table);
		was_col = true;
	}
	else
	{
		colision_counter++;
		if(colision_counter > 8) 
		{
			colision_counter = 0;
			was_col = false;
		}
	}
}

void Collision::calcballTableCol(Ball *ball, Table *table)
{
	if(table->player == 3) ball->velocityVector.x = -ball->velocityVector.x;
	else
	{
	float angle;
	angle = atan2(ball->realPos.y, ball->realPos.x);
	angle -= 1.57f;
	ball->velocityVector = { 2 * ball->velocityVector.x * cos(angle),ball->velocityVector.y * sin(angle) };
	if(ball->velocityVector.y < 0.05) ball->isballmove = false;
	}
}

void Collision::ballRacketCol(Ball *ball,Racket *racket)
{
		unsigned short res = ballRectCheck(ball,racket);
		if(res == 1) 
		{
			if (ball->p1 && racket->whichPlayer==1)
			{
				calcballRacketCol(ball, racket);
				ball->Colision = 0;
				ball->p1 = false;
				ball->p2 = false;
				who = 1;
				ball->isballmove = true;
			}
		}
}

unsigned short Collision::ballRectCheck(Ball *ball, Rect *rect)
{
		GE::Vector2i BP = ball->dObject->getPos();
		GE::Vector2i seg_v = rect->localEP - rect->localSP;
		GE::Vector2i pt_v = BP - rect->localSP;
		int rad_segv = sqrt(seg_v.x*seg_v.x + seg_v.y * seg_v.y);
		GE::Vector2i unit_seg_v = {seg_v.x / rad_segv,seg_v.y / rad_segv};
		int proj_len = pt_v.x * unit_seg_v.x + pt_v.y * unit_seg_v.y;
		GE::Vector2i proj = {proj_len * unit_seg_v.x,proj_len * unit_seg_v.y};
		GE::Vector2i closest;
		if(proj_len > rad_segv) closest = rect->localEP;
		else closest = rect->localSP + proj;


		std::vector<double> distance = {BP.x - closest.x,BP.y - closest.y};
		int distance_len = sqrt(distance[0] * distance[0] + distance[1] * distance[1]);

		int width = 0;
		if(rect->dObject->getSizeX() > rect->dObject->getSizeY()) width = (rect->dObject->getSizeY()/2)+1;
		else if(rect->dObject->getSizeX() < rect->dObject->getSizeY()) width = (rect->dObject->getSizeX()/2)+1;
		if(distance_len <= ball->dObject->getRadius()+width)
		{
			return 1;
		}
		return 0;
}


void Collision::calcballRacketCol(Ball *ball, Racket *racket)
{
ball->velocityVector.x = ((ball->mass - racket->mass)/(ball->mass + racket->mass))*ball->velocityVector.x + 
						((2*racket->mass)/(ball->mass + racket->mass))*racket->quickVelocityVector.x;

ball->velocityVector.y = ((ball->mass - racket->mass)/(ball->mass + racket->mass))*ball->velocityVector.y + 
						((2*racket->mass)/(ball->mass + racket->mass))*racket->quickVelocityVector.y;

}

Collision::~Collision() {
	walls.clear();
	rackets.clear();
	balls.clear();
	tables.clear();
}


