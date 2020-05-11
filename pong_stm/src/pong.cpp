#include "pong.hpp"
#include "ge.hpp"
#include "he.hpp"
#include "Game.hpp"

GE::Display* display;
HE::Radio* radio;
Game* game;
HE::Oled* oled;

//Co się ma dziać przy uruchomieniu
void setup() {
    display = new GE::Display();
    radio = new HE::Radio();
    oled = new HE::Oled();
    game = new Game(oled, radio);
    

    //ssd1306_Init();
    
}

//Pętla wykonująca się 60 razy na sekundę
void gameLoop() {
    //HE::Radio::Response r = radio->getContrInfo();
    //oled->writeLine(0, (char*)"TEST");
    //oled->display();
    //ssd1306_SetCursor(0, 0);
    //ssd1306_WriteString("TEST4", Font_6x8, White);
    //ssd1306_UpdateScreen();
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

