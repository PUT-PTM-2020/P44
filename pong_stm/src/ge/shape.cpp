#include "ge/shape.hpp"

GE::Shape::Shape(uint16_t pX, uint16_t pY, uint16_t c) : pos(pX, pY), color(c) {}

uint16_t GE::Shape::getPosX() { return this->pos.x; }

uint16_t GE::Shape::getPosY() { return this->pos.y; }

GE::Vector2i GE::Shape::getPos() { return this->pos; }

void GE::Shape::setPosX(uint16_t pX) { this->pos.x = pX; }

void GE::Shape::setPosY(uint16_t pY) { this->pos.y = pY; }

void GE::Shape::setPos(GE::Vector2i& p) { this->pos = p; }

void GE::Shape::move(uint16_t x, uint16_t y) {
    this->pos.x += x;
    this->pos.y += y;
}

void GE::Shape::move(GE::Vector2i& v) { this->pos += v; }

void GE::Shape::setColor(uint16_t c) { this->color = c; }
