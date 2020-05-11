#include "ge.hpp"
#include "he.hpp"
#include "Gameplay.hpp"

class Game{
private:
	static float elapsedTime;
	static float simTime;
	static HE::Clock clock,clock1;
	static HE::Clock frameClock;

	static ObjectsVector<UpdateObject*> updateVector;
	static ObjectsVector<GE::Shape*> drawVector,drawOnce;

	HE::Oled *oled;
	HE::Radio *radio;
	
	void calcTimes();
	void checkButtons();
	void displayOled();
	void checkRadio();
	

public:
	Game(HE::Oled* oled, HE::Radio* radio);
	static float timeForBall;
	static const int simPerFrame;
	static bool reset_ball;
	static bool buttonPress;
	static float lastTime;
	static Gameplay *gameplay;

	static float getTime();
	static int getSimPerFrame();
	static float getElapsedTime();
	static float getSimTime();
	static float getTimeForBall();

	static bool oledChange;

	static HE::Radio::Response radioResponse;

	void updateObjects();
	void manageEvents();
	void run();
	void drawObjects();

	static ObjectsVector<UpdateObject*>& getUpdateVector();
	static ObjectsVector<GE::Shape*> & getDrawVector();
	static ObjectsVector<GE::Shape*> & getDrawOnce();
};