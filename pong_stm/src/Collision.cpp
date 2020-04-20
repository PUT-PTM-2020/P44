/*
#include "Collision.hpp"
#include "Game.hpp"
#include <cmath>

ObjectsVector<Wall*> Collision::walls;
ObjectsVector<Racket*> Collision::rackets;
ObjectsVector<Ball*> Collision::balls;
ObjectsVector<Table*> Collision::tables;
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

unsigned short Collision::ballRectCheck(Ball *ball, Rect *rect) {
	sf::Vector2f BP = ball->dObject->getPosition();
	sf::Transform trans = rect->dObject->getTransform();
	sf::Vector2f EP = trans * rect->localEP;
	sf::Vector2f SP = trans * rect->localSP;

	sf::Vector2f vSE = EP - SP;
	sf::Vector2f vBS = BP - SP;

	float lineLenghtPow = vSE.x * vSE.x + vSE.y * vSE.y;

	float t = std::max(0.0f, std::min(lineLenghtPow, vSE.x * vBS.x + vSE.y * vBS.y)) / lineLenghtPow;

	sf::Vector2f TP = SP + t * vSE;

	float distance = Physics::calcDistanceBetweenTwoPoints(TP, BP);
	

	if (distance <= ball->pixelRaidus + rect->pixelRadius) {
		if (t == 0 || t == 1) return 2;
		return 1;
		
	} else {
		return 0;
	}
}

void Collision::ballWallCol(Ball *ball, Wall *wall) {
	
	unsigned short side = ballRectCheck(ball, wall);
	if (side == 0) return;
	else if(Gameplay::mode!=2)
	{
		
	//Pilka nieodbita prez p2
	if (ball->p2 && ball->Colision!=3)
	{

		p1Point(ball,p1);
	
	}

	//Pilka nieodbita prez p1
	else if (ball->p1 && ball->Colision != 3)
	{
		p2Point(ball,p2);
	}

	//serwis w ktoras ze scian p1
	else if (ball->p1Serv == 1 && ball->Colision == 0)
	{
		p2Point(ball,p2);
	}

	//serwis w ktoras ze scian p2
	else if (ball->p2Serv == 1 && ball->Colision == 0)
	{
		p1Point(ball,p1);
	}

	//Nieodpicie pilki przy serwisie przez p1
	else if (ball->Colision == 3 && ball->p1Serv==2)
	{
		p2Point(ball,p2);

	}

	//Nieodpicie pilki przy serwisie przez p2
	else if (ball->Colision == 3 && ball->p2Serv==2)
	{
		p1Point(ball,p1);
	}

	//Serw odbicie od 1 czesci a potem sciana p1
	else if (ball->Colision == 1 && ball->p1==0 && ball->p1Serv==1)
	{
		p2Point(ball,p2);
	}

	//Serw odbicie od 1 czesci a potem sciana p2
	else if (ball->Colision == 1 && ball->p2 == 0 && ball->p2Serv == 1)
	{
		p1Point(ball,p1);
	}
	else if (ball->Colision == 1 && ball->p2)
	{
		p1Point(ball, p1);
	}
	else if (ball->Colision == 1 && ball->p1)
	{
		p2Point(ball, p2);
	}
	else if (ball->Colision == 0 && who==2)
	{
		p1Point(ball, p1);
	}
	else if (ball->Colision == 0 && who==1)
	{
		p2Point(ball, p2);
	}
	}
	else
	{
		if (wall->which_wall == 1 || wall->which_wall == 3)
		{
			ball->velocityVector.x = -ball->velocityVector.x;
	    }
		else if (wall->which_wall == 2)
		{
			ball->velocityVector.y = -ball->velocityVector.y;
		}
	}
}

void Collision::ballRacketCol(Ball *ball, Racket *racket) {
	


	unsigned short side = ballRectCheck(ball, racket);
	if (side == 0) return;
	else if(Gameplay::mode!=2)
	{
		if (ball->p1 &&ball->Colision==3  && racket->whichPlayer==1)
		{
			calcballRacketCol(ball, racket);
			ball->p1Serv = 1;
			ball->p2Serv = 0;
			ball->Colision = 0;
			ball->p1 = false;
			ball->p2 = false;
			who = 1;
			ck.restart();
		}
		else if (!ball->p2 && who == 1 && ball->Colision == 0 && racket->whichPlayer==2)
		{
			
			p1Point(ball, p1);
		}

		else if (ball->p2 && ball->Colision == 3 && racket->whichPlayer == 2)
		{
			calcballRacketCol(ball, racket);
			ball->p1Serv = 0;
			ball->p2Serv = 1;
			ball->Colision = 0;
			ball->p1 = false;
			ball->p2 = false;
			who = 2;
			ck.restart();
		}
		else if (!ball->p1 && who == 2 && ball->Colision == 0 && racket->whichPlayer == 1)
		{
			p2Point(ball, p2);
		}
		else if (ball->p2 && ball->Colision!=0 && racket->whichPlayer == 2 && ck.getElapsedTime().asMilliseconds()>200)
		{
			ball->Colision = 0;
			calcballRacketCol(ball, racket);
			ball->p1 = false;
			ball->p2 = false;
			who = 2;
		}
		else if (!ball->p2 && ball->Colision != 0 && racket->whichPlayer == 2)
		{
			p1Point(ball, p1);
		}


		else if (ball->p1 && ball->Colision != 0 && racket->whichPlayer == 1 && ck.getElapsedTime().asMilliseconds() > 200)
		{
			ball->Colision = 0;
			calcballRacketCol(ball, racket);
			ball->p1 = false;
			ball->p2 = false;
			who = 1;

		}
		else if (!ball->p1 && ball->Colision!=0 && racket->whichPlayer == 1)
		{
			p2Point(ball, p2);
		}
	}
	else
	{
		if (ck.getElapsedTime().asMilliseconds() > 200)
		{
			calcballRacketCol(ball, racket);
			ck.restart();
		}
	}
	


}

void Collision::ballTableCol(Ball *ball, Table *table)
{
	float time=0;
	unsigned short side = ballRectCheck(ball, table);
	if (side == 0) return;
	else if (Gameplay::mode != 2)
	{
	if (table->player != 3)
	{

		//Serw pierwsze odbicie p1
		if (ball->p1Serv == 1 && ball->p1 == 0 && ball->Colision == 0 && table->player == 1)
		{
			ck.restart();
			time = ball->simTime;
			ball->Colision = 1;
			calcballTableCol(ball, table);
		}

		//Serw pierwsze odbicie p2
		else if (ball->p2Serv == 1 && ball->p2 == 0 && ball->Colision == 0 && table->player == 2)
		{
			ck.restart();
			time = ball->simTime;
			ball->Colision = 1;
			calcballTableCol(ball, table);
		}

		//Nieprawidlowo wykonany serw p1 odrazu na 2 polowe
		else if (ball->p1Serv == 1 && ball->p1 == 0 && ball->Colision == 0 && table->player == 2)
		{
			p2Point(ball, p2);
		}

		//Nieprawidlowo wykonany serw p2 odrazu na 2 polowe
		else if (ball->p2Serv == 1 && ball->p2 == 0 && ball->Colision == 0 && table->player == 1)
		{
			p1Point(ball, p1);
		}

		//Nieprawidolwe podwojne odbicie p1 od tej samemj strony
		else if (ball->p1Serv == 1 && ball->p1 == 0 && ball->Colision == 1 && ck.getElapsedTime().asMilliseconds() > 400 && table->player == 1)
		{
			p2Point(ball, p2);
		}

		//Nieprawidolwe podwojne odbicie p2 od tej samemj strony
		else if (ball->p2Serv == 1 && ball->p2 == 0 && ball->Colision == 1 && ck.getElapsedTime().asMilliseconds() > 400 && table->player == 2)
		{
			p1Point(ball, p1);
		}

		//Drugie odbicie po serwie p1
		else if (ball->p1Serv == 1 && ball->p1 == 0 && ball->Colision == 1 && table->player == 2)
		{
			ck.restart();
			time = ball->simTime;
			ball->p2 = true;
			ball->p1Serv = 0;
			ball->Colision = 2;
			calcballTableCol(ball, table);

		}

		//Drugie odbicie po serwie p2
		else if (ball->p2Serv == 1 && ball->p2 == 0 && ball->Colision == 1 && table->player == 1)
		{
			ck.restart();
			time = ball->simTime;
			ball->p1 = true;
			ball->p2Serv = 0;
			ball->Colision = 2;
			calcballTableCol(ball, table);
		}

		//Nieodebrana pilka przez p1 
		else if (ball->p1 && ball->Colision == 2 && table->player == 1 && ck.getElapsedTime().asMilliseconds() > 400)
		{
			p2Point(ball, p2);
		}

		//Nieodebrana pilka przez p2 
		else if (ball->p2 && ball->Colision == 2 && table->player == 2 && ck.getElapsedTime().asMilliseconds() > 400)
		{
			p1Point(ball, p1);
		}

		//Odbicie w normlanej grze we wlasny stol przez p1
		else if (who == 1 && ball->Colision == 0 && table->player == 1)
		{
			p2Point(ball, p2);
		}

		//Prawidlowe odbicie w nornalnej grze p1
		else if (who == 1 && ball->Colision == 0 && table->player == 2)
		{
			calcballTableCol(ball, table);
			ball->p2 = true;
			ball->Colision = 1;
		}

		//Odbicie w normlanej grze we wlasny stol przez p2
		else if (who == 2 && ball->Colision == 0 && table->player == 2)
		{
			p1Point(ball, p1);
		}

		//Prawidlowe odbicie w nornalnej grze p2
		else if (who == 2 && ball->Colision == 0 && table->player == 1)
		{
			time = ball->simTime;
			ck.restart();
			calcballTableCol(ball, table);
			ball->p1 = true;
			ball->Colision = 1;
		}
		else if (ball->Colision == 1 && ck.getElapsedTime().asMilliseconds() > 400 && p1)
		{
			p2Point(ball, p2);
		}
		else if (ball->Colision == 1 && ck.getElapsedTime().asMilliseconds() > 400 && p2)
		{
			p1Point(ball, p1);
		}


	}
	else
	{
		if (ck1.getElapsedTime().asMilliseconds() > 100 && side == 1)
		{
			ball->velocityVector.x = -ball->velocityVector.x * 0.4f;
			ck1.restart();
		}
		if (ck1.getElapsedTime().asMilliseconds() > 100 && side == 2)
		{
			ball->velocityVector.y = -ball->velocityVector.y * 0.3f;
			ck1.restart();
		}
	}
	}
	else //Tryb wolny
	{
	if (table->player != 3)
	{
		if (ck1.getElapsedTime().asMilliseconds() > 100)
		{
			calcballTableCol(ball, table);
			ck1.restart();
		}
	}
	else
	{
		if (ck1.getElapsedTime().asMilliseconds() > 100 && side == 1)
		{
			ball->velocityVector.x = -ball->velocityVector.x * 0.4f;
			ck1.restart();
		}
		if (ck1.getElapsedTime().asMilliseconds() > 100 && side == 2)
		{
			ball->velocityVector.y = -ball->velocityVector.y * 0.3f;
			ck1.restart();
		}
	}

	}

}

void Collision::p1Point(Ball *ball,Player *p)
{
	ball->dObject->setPosition(Gameplay::default_ballLPos);
	ball->velocityVector = { 0.0f, 0.0f };
	ball->realPos = { Physics::calcRealValue(ball->dObject->getPosition().x),
	-Physics::calcRealValue(ball->dObject->getPosition().y) };
	ball->isballmove = false;
	ball->Colision = 0;
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
	ball->dObject->setPosition(Gameplay::default_ballRPos);
	ball->velocityVector = { 0.0f, 0.0f };
	ball->realPos = { Physics::calcRealValue(ball->dObject->getPosition().x),
	-Physics::calcRealValue(ball->dObject->getPosition().y) };
	ball->isballmove = false;
	ball->Colision = 0;
	ball->p2Serv = 2;
	ball->p1Serv = 0;
	ball->p1 = true;
	ball->p2 = false;
	Game::timeForBall = 0;
	Gameplay::player2Score++;
	p->points++;
	who = 0;
	
}


void Collision::calcballTableCol(Ball *ball, Table *table)
{
	float angle;
	angle = atan2(ball->realPos.y, ball->realPos.x);
	angle -= 1.57f;
	ball->velocityVector = { 2 * ball->velocityVector.x * cos(angle),ball->velocityVector.y * sin(angle) };
	Game::b.play();
}


void Collision::calcballRacketCol(Ball *ball, Racket *racket)
{
	sf::Transform trans = racket->dObject->getTransform();
	sf::Vector2f SP = trans * racket->localSP;
	sf::Vector2f EP = trans * racket->localEP;
	float angle;
	float tgalfa;
	ball->isballmove = true;

	float a2;
	if (ball->velocityVector.x == 0 && ball->velocityVector.y == 0)
		a2 = 0;
	else
	{
		sf::Vector2f oldBallPosPix = Physics::calcPixelVector(ball->oldRealPos);
		sf::Vector2f BallPosPix = Physics::calcPixelVector(ball->realPos);
		if (oldBallPosPix.x == BallPosPix.x || oldBallPosPix.y == BallPosPix.y)
		{
			a2 = 0;
		}
		else
			a2 = Physics::calcDirectionFactor(oldBallPosPix.x, oldBallPosPix.y, BallPosPix.x, BallPosPix.y);
	}


	if (SP.y == EP.y)
	{
		tgalfa = atan2(ball->dObject->getPosition().y, ball->dObject->getPosition().x);
		tgalfa = 1.57079f- tgalfa;
	}
	else if (SP.x == EP.x)
	{
		tgalfa = atan2(ball->dObject->getPosition().y, ball->dObject->getPosition().x);
	}
	else
	{
		float a1 = Physics::calcDirectionFactor(SP.x, SP.y, EP.x, EP.y);
		tgalfa = abs(((a2 - a1) / (1 + a1 * a2)));
		tgalfa = atan(tgalfa);
		tgalfa = 1.570796f - tgalfa;
	}
	angle = tgalfa;
	if (angle > 1.4f) angle = 1.3f;
	else if (angle < -1.4f) angle = -1.3f;
	if (racket->velocityVector.x == 0 && racket->velocityVector.y == 0)
	{
		if (racket->angle>0 && racket->angle<90 && ball->p1)
		{
			ball->velocityVector = { -ball->velocity*cos(angle) , ball->velocity*sin(angle) };
		}
		else if (ball->p1)
		{
			ball->velocityVector = { ball->velocity*cos(angle) , ball->velocity*sin(angle) };
		}
		else if (racket->angle < 0 && racket->angle >-90  && ball->p2)
		ball->velocityVector = { ball->velocity*cos(angle) , ball->velocity*sin(angle) };
		else if(ball->p2)
		ball->velocityVector = { -ball->velocity*cos(angle) , ball->velocity*sin(angle) };

	}
	else
	{
		
		ball->velocityVector = { ((((racket->velocityVector.x - ball->velocityVector.x)*racket->mass*cos(angle)
			+ (racket->velocityVector.x*racket->mass) + (ball->mass*ball->velocityVector.x)) / ((racket->mass + ball->mass)*cos(angle))) / 2.0f),
			((((racket->velocityVector.y - ball->velocityVector.y)*racket->mass*sin(angle)
			+ (racket->velocityVector.y*racket->mass) + (ball->mass*ball->velocityVector.y)) / ((racket->mass + ball->mass)*sin(angle))) / 2.0f)

		};

	}
	Game::b.play();
}


Collision::~Collision() {
	walls.clear();
	rackets.clear();
	balls.clear();
	tables.clear();
}



*/
