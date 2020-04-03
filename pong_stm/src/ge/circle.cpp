#include "ge/circle.hpp"

GE::Circle::Circle(uint16_t r, uint16_t pX, uint16_t pY, uint16_t c) : Shape(pX, pY, c), radius(r) {}

uint16_t GE::Circle::getRadius() { return this->radius; }

void GE::Circle::setRadius(uint16_t r) { this->radius = r; }

void GE::Circle::draw() {
    BSP_LCD_SetTextColor(this->color);
    BSP_LCD_FillCircle(this->pos.x, this->pos.y, this->radius);
}

