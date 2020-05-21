#include "ge/shape.hpp"
#include "Physics.hpp"

GE::Shape::Shape(uint16_t pX, uint16_t pY, uint16_t c) : newPos(pX, pY), oldPos(pX, pY), color(c) {}

uint16_t GE::Shape::getPosX() { return this->newPos.x; }

uint16_t GE::Shape::getPosY() { return this->newPos.y; }

GE::Vector2i GE::Shape::getPos() { return Physics::swapYR(newPos); }

void GE::Shape::setPosX(uint16_t pX) { 
    this->oldPos.x = this->newPos.x;
    this->newPos.x = pX; 
}

void GE::Shape::setPosY(uint16_t pY) { 
    this->oldPos.y = this->newPos.y;
    this->newPos.y = pY; 
}

void GE::Shape::setPos(GE::Vector2i& p) { 
    this->oldPos = this->newPos;
    this->newPos = p; 
}

void GE::Shape::setNewPosOnly(Vector2i& p) {
    this->newPos = p; 
}

void GE::Shape::move(uint16_t x, uint16_t y) {
    this->oldPos = this->newPos;
    this->newPos.x += x;
    this->newPos.y += y;
}

void GE::Shape::move(GE::Vector2i& v) { 
    this->oldPos = this->newPos;
    this->newPos += v; 
}

void GE::Shape::setColor(uint16_t c) { this->color = c; }
