#include "pong.hpp"
#include "ge.hpp"
#include "he.hpp"
#include <string>
#include "Game.hpp"

GE::Display* display;
Game* game;


//Co się ma dziać przy uruchomieniu
void setup() {
    display = new GE::Display();
    game = new Game();
    
}

//Pętla wykonująca się 60 razy na sekundę
void gameLoop() {
    game->run();

}


//Pętla nieskończona (wykonuje się pomiędzy gameLoop())
void loop() {
    
    
}

