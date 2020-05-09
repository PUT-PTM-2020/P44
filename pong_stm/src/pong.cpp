#include "pong.hpp"
#include "ge.hpp"
#include "he.hpp"
#include <string>
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
    radio->getContrInfo();
    game->run();
    
}


//Pętla nieskończona (wykonuje się pomiędzy gameLoop())
void loop() {
    
    
}

