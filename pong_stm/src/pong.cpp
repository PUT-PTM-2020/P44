#include "pong.hpp"
#include "ge.hpp"
#include "he.hpp"
#include <string>
#include "Game.hpp"

GE::Display* display;
Game* game;

HE::Clock* clock;
HE::Radio* radio;

//Co się ma dziać przy uruchomieniu
void setup() {
    display = new GE::Display();
    game = new Game();
    clock = new HE::Clock();
    radio = new HE::Radio();
    radio->getControllersAcc();

    
    
}

//Pętla wykonująca się 60 razy na sekundę
void gameLoop() {
    game->run();

    HAL_UART_Transmit_IT(&huart2, (uint8_t*)(std::to_string(clock->getTime()).c_str()), strlen(std::to_string(clock->getTime()).c_str()));
    
}


//Pętla nieskończona (wykonuje się pomiędzy gameLoop())
void loop() {
    
    
}

