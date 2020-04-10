#include "pong.hpp"
#include "ge.hpp"

GE::Display dis;
GE::Circle cir(10, 10, 10);

//Co się ma dziać przy uruchomieniu
void setup() {
    dis.init();
}

//Pętla wykonująca się 60 razy na sekundę
void gameLoop() {
    cir.draw();
    cir.move(1, 1);
    
}


//Pętla nieskończona (wykonuje się pomiędzy gameLoop())
void loop() {
    
    
}

