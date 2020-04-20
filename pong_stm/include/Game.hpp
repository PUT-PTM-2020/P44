#include "ge.hpp"
#include "Gameplay.hpp"

class Game{

	static float lastTime;
	static float elapsedTime;
	static float simTime;
	static HE::Clock  clock,clock1;
	static HE::Clock  frameClock;

	static ObjectsVector<UpdateObject*> updateVector;
	static ObjectsVector<GE::Shape*> drawVector,drawOnce;
	static void calcTimes();
public:

	Game();
	static float timeForBall;
	static const int simPerFrame;
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
	static ObjectsVector<GE::Shape*> & getDrawOnce();
};