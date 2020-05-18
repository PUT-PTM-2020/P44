#include "pong.hpp"
#include "ge.hpp"
#include "he.hpp"
#include "Game.hpp"

//Wskaźniki na obiekty muszą być utworzone w zasięgu gloablnym, aby takie były w main.cpp (od cube)
HE::Radio* radio;
HE::Oled* oled;
GE::Display* display;
Game* game;

//Co się ma dziać przy uruchomieniu
void setup() {
    //Inicjalizacja obiektów
    radio = new HE::Radio();
    oled = new HE::Oled();
    display = new GE::Display();
    game = new Game(oled, radio);
    
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

