#pragma once
#include "PhysicalObject.hpp"
#include "MovingObject.hpp"

#define BALL_DEFAULT_PIXEL_RADIUS 4.0f
#define BALL_DEFAULT_DRAG 0.47f
#define BALL_DEFAULT_MASS 0.0025f

class Ball : public PhysicalObject, public MovingObject, public DrawnObject<GE::Circle> {
	friend class Collision;
	friend class Player;
private:
	float pixelRaidus, realRaidus;
	float drag;
	float dragK;
	bool p1 , p2; //Gracze, mowi ktory gracz ma w danym momencie prawo do odbicia pilki
	int p1Serv, p2Serv; //0 - nie serwowal, 1 - serwowal, 2 - bedzie serwowal
	bool isballmove; // mowi czy pilka sie porusza
	int Colision; //licznik odbic od stołu -1 - jeszcze nei bylo odbicia, 0 - odbicie od stolu przy serwie, 1 - 1 odbicie przy normalnej grze, 2 - 2 odbicai przy normalnej grze
	int pomoc; //To regulacji mocy porzucenia
	GE::Vector2f acc;
	GE::Vector2f oldVelocityVector;
	void applyGravity();
	void applyWind();
	void applyAirResistance(const float &velocity, const GE::Vector2f &unitVector);
	void applyForces();
	GE::Vector2f calcNewRealPos(const GE::Vector2f &lastRealPos, const GE::Vector2f &velocityVector, const GE::Vector2f &acc, const float &time);
public:
	Ball(float posX, float posY);
	void setPixelSize(const float &pixelRaidus);
	void update();
	void simulation(GE::Vector2i *pos);
	void setPos(GE::Vector2i pos);
	GE::Vector2i getPos();
	~Ball();
	void test();
	

};


