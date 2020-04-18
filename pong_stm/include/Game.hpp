#include "ge.hpp"
#include "Gameplay.hpp"

class Game{
	static const int simPerFrame;
	static float lastTime;
	static float elapsedTime;
	static float simTime;
	static int  clock,clock1;
	static int  frameClock;

	static ObjectsVector<UpdateObject*> updateVector;
	static ObjectsVector<GE::Shape*> drawVector;
	static void calcTimes();
public:

	static float timeForBall;
	static bool reset_ball;
	static bool buttonPress;

	static Gameplay *gameplay;

	static float getTime();
	static int getSimPerFrame();
	static float getElapsedTime();
	static float getSimTime();
	static float getTimeForBall();

	void updateObjects();
	void manageEvents();
	void run();
	void drawObjects();

	static ObjectsVector<UpdateObject*>& getUpdateVector();
	static ObjectsVector<GE::Shape*> & getDrawVector();
};