#pragma once
#include "ge.hpp"
class SimObject {
private:
	virtual void sendSimObject();
	virtual void deleteSimObject();
protected:
	float simTime;
	int simPerFrame;
	void getSimTime();
public:
	SimObject();
	virtual void simulation(GE::Vector2i *pos) = 0;
	virtual void setPos(GE::Vector2i pos) = 0;
	virtual GE::Vector2i getPos() = 0;
	virtual ~SimObject();
};

