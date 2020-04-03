#include "pong.hpp"
#include "ge.hpp"

GE::Display dis;
GE::Rect rec(10, 10, 10, 10);

void setup() {
    dis.init();
    rec.draw();
    rec.move(10, 10);
    rec.draw();
}

void loop() {
    
}