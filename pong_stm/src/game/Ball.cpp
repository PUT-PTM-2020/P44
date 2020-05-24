#include "Ball.hpp"
#include "Game.hpp"

Ball::Ball(float posX, float posY) : 
	DrawnObject(new GE::Circle(BALL_DEFAULT_PIXEL_RADIUS,10,10,GE::Color::red),1),
	PhysicalObject(Physics::Materials::wood, posX, posY),
	MovingObject(BALL_DEFAULT_MASS) {
	this->pixelRaidus = BALL_DEFAULT_PIXEL_RADIUS;
	this->realRaidus = Physics::calcRealValue(BALL_DEFAULT_PIXEL_RADIUS);
	this->drag = BALL_DEFAULT_DRAG;
	this->dragK = (-0.5f * Physics::viscosity * 2.0f * PI * pow(this->realRaidus, 2) * this->drag) / this->mass;
	this->acc = { 0.0f, 0.0f };
	GE::Vector2i q= (Physics::swapY({posX,posY}));
	this->dObject->setPos(q);
	Collision::getBallCollisionVector()._add(this);
	isballmove = false;
	Colision = -1;
	p1Serv = 2; 
	p2Serv = 0; 
	p1 = false;
	p2 = false;
	pomoc = 0;

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


void Ball::setPos(GE::Vector2i pos)
{
	this->dObject->setPos(pos);
}


GE::Vector2i Ball::getPos()
{
	return dObject->getPos();
}

void Ball::simulation(GE::Vector2i *pos) {
	acc = { 0.0f, 0.0f };
		if (isballmove)
		{
			oldVelocityVector = velocityVector;
			oldRealPos = realPos;
			realPos = calcNewRealPos(oldRealPos, velocityVector, acc, simTime);
			velocityVector = calcVelocityVector(oldRealPos, realPos, simTime);
			velocity = calcVelocityFromVelocityVector(velocityVector);
			unitVector = calcUnitVector(velocityVector, velocity);
            *pos = Physics::floatVectorToIntVector(Physics::calcPixelVector(realPos));
		}
		
		else
		{
				if (Game::radioResponse.startContr1 && p1Serv == 2)
				{
					pomoc++;//Zliacznie mocy
				}
				else if(!Game::radioResponse.startContr1 && p1Serv == 2 )
				{
					pomoc = pomoc/300;//liczba sekund od wcisniecia do puszczenia przycisku
					pomoc++;
					if(pomoc > 6) pomoc = 6;
					velocityVector = {0,pomoc};
					p1 = !p1;
					p2 = !p2;
					pomoc = 0;
				}
				
		}
}

Ball::~Ball() {
	//Collision::getBallCollisionVector()._delete(this);
}

