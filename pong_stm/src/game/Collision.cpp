
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

//Iterowanie po obiektach w celu sprawdzenia czy wystąpiła kolizja między nimi a piłeczką
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
	//Pilka nieodbita prez p2
	if(p2 && ball->Colision == 1)
	{
		p1Point(ball,p1);
	}

	//Pilka nieodbita prez p1
	if(p1 && ball->Colision == 1)
	{
		p2Point(ball,p2);
	}
	//serwis w ktoras ze scian p1
	if(ball->p1Serv == 1 && ball->Colision == -1)
	{
		p2Point(ball,p2);
	}

	//serwis w ktoras ze scian p2
	if(ball->p2Serv == 1 && ball->Colision == -1)
	{
		p1Point(ball,p1);
	}

	//Nieodpicie pilki przy serwisie przez p1


	//Nieodpicie pilki przy serwisie przez p2


	//Serw odbicie od 1 czesci a potem sciana p1


	//Serw odbicie od 1 czesci a potem sciana p2

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
	if(res == 1 && !was_col && table->player!=3)
	{
		was_col = true;
		//Serw pierwsze odbicie p1
		if(ball->p1Serv == 1 && ball->Colision == -1 && table->player == 1 && ball->p1 == 0)
		{
			calcballTableCol(ball,table);
			was_col = true;
			ball->Colision = 0;
			return;
		}
		//Serw pierwsze odbicie p2
		if(ball->p2Serv == 1 && ball->Colision == -1 && table->player == 2 && ball->p2 == 0)
		{
			calcballTableCol(ball,table);
			was_col = true;
			ball->Colision = 0;
			return;
		}

		//Nieprawidlowo wykonany serw p1 odrazu na 2 polowe
		if(ball->p1Serv == 1 && ball->Colision == -1 && table->player == 2 && ball->p1 == 0)
		{
			p2Point(ball,p2);
			return;
		}

		//Nieprawidlowo wykonany serw p2 odrazu na 2 polowe
		if(ball->p2Serv == 1 && ball->Colision == -1 && table->player == 1 && ball->p2 == 0)
		{
			p1Point(ball,p1);
			return;
		}

		//Nieprawidolwe podwojne odbicie p1 od tej samemj strony przy serwie
		if(ball->p1Serv == 1 && ball->Colision == 0 && table->player == 1 && ball->p1 == 0)
		{
			p2Point(ball,p2);
			return;
		}

		//Nieprawidolwe podwojne odbicie p2 od tej samemj strony przy serwie
		if(ball->p2Serv == 1 && ball->Colision == 0 && table->player == 2 && ball->p2 == 0)
		{
			p1Point(ball,p1);
			return;
		}

		//Drugie odbicie po serwie p1
		if(ball->p1Serv == 1 && ball->Colision == 0 && table->player == 2 && ball->p1 == 0)
		{
			calcballTableCol(ball,table);
			was_col = true;
			ball->Colision = 1;
			return;
		}

		//Drugie odbicie po serwie p2
		if(ball->p2Serv == 1 && ball->Colision == 0 && table->player == 1 && ball->p2 == 0)
		{
			calcballTableCol(ball,table);
			was_col = true;
			ball->Colision = 1;
			return;
		}

		//Nieodebrana pilka przez p1 
		if(ball->p1 && ball->Colision == 1 && table->player == 2)
		{
			p2Point(ball,p2);
			return;
		}

		//Nieodebrana pilka przez p2 
		if(ball->p2 && ball->Colision == 1 && table->player == 2)
		{
			p1Point(ball,p1);
			return;
		}

		//Odbicie w normlanej grze we wlasny stol przez p1
		if(ball->p1 == 0 && ball->Colision == 0 && table->player == 1)
		{
			p2Point(ball,p2);
			return;
		}

		//Odbicie w normlanej grze we wlasny stol przez p2
		if(ball->p2 == 0 && ball->Colision == 0 && table->player == 2)
		{
			p1Point(ball,p1);			
			return;
		}
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
	if(table->player == 3 && res == 1)
	{
		ball->velocityVector.x = -ball->velocityVector.x;
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
			//Odbicie prawidlowe w normlanej grze przez p1
			if (ball->p1 && racket->whichPlayer==1 && ball->Colision == 1)
			{
				calcballRacketCol(ball, racket);
				ball->isballmove = true;
				ball->Colision = 0;
				ball->p1 = false;
				ball->p2 = false;
				return;
			}
			//Odbicie prawidlowe w normlanej grze przez p2
			if (ball->p2 && racket->whichPlayer==2 && ball->Colision == 1)
			{
				calcballRacketCol(ball, racket);
				ball->Colision = 0;
				ball->p1 = false;
				ball->p2 = false;
				return;
			}
			//Serw p1
			if(ball->p1 && racket->whichPlayer==1 && ball->Colision == -1 && ball->p1Serv == 2)
			{
				calcballRacketCol(ball, racket);
				ball->isballmove = true;
				ball->p1 = false;
				ball->p2 = true;
				ball->p1Serv = 1;
				return;
			}
			//Serw p2
			if(ball->p2 && racket->whichPlayer==2 && ball->Colision == -1 && ball->p2Serv == 2)
			{
				calcballRacketCol(ball, racket);
				ball->p2 = false;
				ball->p1 = true;
				ball->p2Serv = 1;
				return;
			}
			//Nieprawidlowe odbicie przez p1
			if(ball->p2 && racket->whichPlayer==1 && ball->Colision > -1)
			{
				//p2Point(ball,p2);
				return;
			}
			//Nieprawidlowe odbicie przez p2
			if(ball->p1 && racket->whichPlayer==2 && ball->Colision > -1)
			{
				p1Point(ball,p1);
				return;
			}
		}
}

unsigned short Collision::ballRectCheck(Ball *ball, Rect *rect)
{
		GE::Vector2f BP = {(float)ball->dObject->getPos().x,(float)ball->dObject->getPos().y}; //pobranie pozycji piłeczki
		GE::Vector2f seg_v = {(float)rect->localEP.x - (float)rect->localSP.x,(float)rect->localEP.y - (float)rect->localSP.y};//SP - start point , EP - end point. Punkty potrzbne do utworzenia wektora 
		GE::Vector2f SP = {(float)rect->localSP.x,(float)rect->localSP.y};

		GE::Vector2f pt_v = BP - SP;
		float rad_segv = sqrt(seg_v.x*seg_v.x + seg_v.y * seg_v.y);
		GE::Vector2f unit_seg_v = {seg_v.x / rad_segv,seg_v.y / rad_segv};
		float proj_len = pt_v.x * unit_seg_v.x + pt_v.y * unit_seg_v.y;
		GE::Vector2f proj = {proj_len * unit_seg_v.x,proj_len * unit_seg_v.y};
		GE::Vector2f closest;
		if(proj_len < 0) closest = SP;
		else if (proj_len > rad_segv) closest = {rect->localEP.x,rect->localEP.y};
		else closest = {(float)rect->localSP.x + (float)proj.x,(float)rect->localSP.y + (float)proj.y};


		std::vector<float> distance = {(float)BP.x - (float)closest.x,(float)BP.y - (float)closest.y};
		float distance_len = sqrt(distance[0] * distance[0] + distance[1] * distance[1]);
		int x = distance_len;
		float width = 0;
		if(rect->dObject->getSizeX() > rect->dObject->getSizeY()) width = (rect->dObject->getSizeY()/2)+3;
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
ball->isballmove = true;
}


void Collision::p1Point(Ball *ball,Player *p)
{
	GE::Vector2i q = ball->dObject->getPos();
	q= (Physics::swapY(Gameplay::default_ballLPos));
	ball->dObject->setNewPosOnly(q);
	ball->velocityVector = { 0.0f, 0.0f };
	ball->realPos = Physics::calcRealVector(ball->getPos());
	ball->isballmove = false;
	ball->Colision = -1;
	ball->p1Serv = 2;
	ball->p2Serv = 0;
	ball->p1 = false;
	ball->p2 = true;
	Game::timeForBall = 0;
	Gameplay::player1Score++;
	p->points++;
	who = 0;

}

void Collision::p2Point(Ball *ball,Player *p)
{
	GE::Vector2i q = ball->dObject->getPos();
	q= (Physics::swapY(Gameplay::default_ballRPos));
	ball->dObject->setNewPosOnly(q);
	ball->velocityVector = { 0.0f, 0.0f };
	ball->realPos = Physics::calcRealVector(ball->getPos());
	ball->isballmove = false;
	ball->Colision = -1;
	ball->p2Serv = 2;
	ball->p1Serv = 0;
	ball->p1 = true;
	ball->p2 = false;
	Game::timeForBall = 0;
	Gameplay::player2Score++;
	p->points++;
	who = 0;
	
}

Collision::~Collision() {
	walls.clear();
	rackets.clear();
	balls.clear();
	tables.clear();
}


