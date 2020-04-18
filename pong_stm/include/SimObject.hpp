#pragma once
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
	virtual void simulation() = 0;
	virtual ~SimObject();
};

