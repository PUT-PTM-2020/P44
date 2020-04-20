#include "pong.hpp"
#include "ge.hpp"
#include "he.hpp"
#include <string>

GE::Display* display;
HE::Clock* clock;
HE::Radio* radio;

//Co się ma dziać przy uruchomieniu
void setup() {
    display = new GE::Display();
    clock = new HE::Clock();
    radio = new HE::Radio();
    

    
    
}

//Pętla wykonująca się 60 razy na sekundę
void gameLoop() {
    radio->getControllersAcc();
    
}


//Pętla nieskończona (wykonuje się pomiędzy gameLoop())
void loop() {
    
    
}

