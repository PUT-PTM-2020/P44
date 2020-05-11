#include "pong.hpp"
#include "ge.hpp"
#include "he.hpp"
#include "Game.hpp"

GE::Display* display;
HE::Clock* clock;
HE::Radio* radio;
Game* game;

//Co się ma dziać przy uruchomieniu
void setup() {
    display = new GE::Display();
    clock = new HE::Clock();
    radio = new HE::Radio();
    game = new Game();
    
}

//Pętla wykonująca się 60 razy na sekundę
void gameLoop() {
    HE::Radio::Response r = radio->getContrInfo();

    //***DEBUG***
    //char buf[100];
    //sprintf(buf, "accX1: %d accY1: %d | accX2: %d accY2: %d", (int16_t)r.accContr1.x, (int16_t)r.accContr1.y, (int16_t)r.accContr2.x, (int16_t)r.accContr2.y);
    //HE::Debug::sendUART(buf);
    //******

    game->run();
    
}


//Pętla nieskończona (wykonuje się pomiędzy gameLoop())
void loop() {
    
    
}

