#include "Ball.hpp"
#include "Game.hpp"

Ball::Ball(float posX, float posY) : 
	DrawnObject(new GE::Circle(BALL_DEFAULT_PIXEL_RADIUS,10,10)),
	PhysicalObject(Physics::Materials::wood, posX, posY),
	MovingObject(BALL_DEFAULT_MASS) {
	this->pixelRaidus = BALL_DEFAULT_PIXEL_RADIUS;
	this->realRaidus = Physics::calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->drag = BALL_DEFAULT_DRAG;
	this->dragK = (-0.5f * Physics::viscosity * 2.0f * PI * pow(this->realRaidus, 2) * this->drag) / this->mass;
	this->acc = { 0.0f, 0.0f };

	//this->dObject->setPosition(Physics::swapY({ posX, posY }));
	isballmove = false;
	p1Serv = 2; 
	p2Serv = 0; 
	p1 = false;
	p2 = false;
	pomoc = 0;
	//Collision::getBallCollisionVector()._add(this);
}
   
void Ball::applyGravity() {
	acc += {0, -Physics::grav};
}

void Ball::applyWind()
{
	acc += {Physics::wind, 0};
}

void Ball::applyAirResistance(const float &v, const GE::Vector2f &uV) {
	if (v != 0.0f) {
		acc += uV * dragK * (float)pow(v, 2);
	}
}

void Ball::applyForces() {
	applyGravity();
	applyWind();
	applyAirResistance(velocity, unitVector);
}

GE::Vector2f Ball::calcNewRealPos(const GE::Vector2f &lV, const GE::Vector2f &vV, const GE::Vector2f &acc, const float &t) {

	if(isballmove && (p1Serv!=2 || p2Serv!=2))applyForces();
	return lV + (((2.0f * vV) + (acc * t)) * t) * 0.5f;
}

void Ball::setPixelSize(const float &pR) {
	dObject->setRadius(pR);
	realRaidus = Physics::calcRealValue(pR);
}

void Ball::update() {
	getSimTime();
	
}

void Ball::simulation() {
	acc = { 0.0f, 0.0f };
		if (Game::reset_ball)
		{
			isballmove = false;
			velocityVector = { 0.0f,0.0f };
			Game::timeForBall = 0;
			dObject->setPos(Gameplay::default_ballLPos);
			realPos = { Physics::calcRealValue(dObject->getPosX()),
			-Physics::calcRealValue(dObject->getPosY())};
			Game::reset_ball = false;
		}
		if (isballmove)
		{
			oldVelocityVector = velocityVector;
			oldRealPos = realPos;
			realPos = calcNewRealPos(oldRealPos, velocityVector, acc, simTime);
			velocityVector = calcVelocityVector(oldRealPos, realPos, simTime);
			if (velocityVector.y > 3.0f) velocityVector.y = 3.0f;
			if (velocityVector.x > 8.0f) velocityVector.x = 8.0f;
			velocity = calcVelocityFromVelocityVector(velocityVector);
			unitVector = calcUnitVector(velocityVector, velocity);
            GE::Vector2i e = Physics::swapY(Physics::calcPixelVector(realPos));
            dObject->setPos(e);
		}
		else
		{
			float pomoc = Game::getTimeForBall();
				if (pomoc !=0)
				{
					isballmove = true;
					velocityVector.y = 3.0f * pomoc;
					if (velocityVector.y > 5) velocityVector.y = 5;
					p1 = !p1;
					p2 = !p2;
					Colision = 3;
					pomoc = 0;
				}
				
		}
}

Ball::~Ball() {
	//Collision::getBallCollisionVector()._delete(this);
}

void Ball::test() {
	
}

