#include "pong.hpp"
#include "ge.hpp"

GE::Display dis;
GE::Rect rect(10, 10, 10, 10);

//Co się ma dziać przy uruchomieniu
void setup() {
    dis.init();
}

//Pętla wykonująca się 60 razy na sekundę
void gameLoop() {
    
    rect.move(10, 10);
    rect.draw();
}

//Pętla nieskończona (wykonuje się pomiędzy gameLoop())
void loop() {
    
    
}

