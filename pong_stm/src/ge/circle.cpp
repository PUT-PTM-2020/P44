#include "ge/circle.hpp"

GE::Circle::Circle(uint16_t r, uint16_t pX, uint16_t pY, uint16_t c) : Shape(pX, pY, c), newRadius(r), oldRadius(r) {}

uint16_t GE::Circle::getRadius() { return this->newRadius; }

void GE::Circle::setRadius(uint16_t r) { 
    this->oldRadius = this->newRadius;
    this->newRadius = r; 
}

void GE::Circle::draw() {
    if (newPos != oldPos || newRadius != oldRadius) {
        BSP_LCD_SetTextColor(BSP_LCD_GetBackColor());
        BSP_LCD_FillCircle(this->oldPos.x, this->oldPos.y, this->oldRadius);
    }
    BSP_LCD_SetTextColor(this->color);
    BSP_LCD_FillCircle(this->newPos.x, this->newPos.y, this->newRadius);
}

GE::Circle::~Circle() {
    BSP_LCD_SetTextColor(BSP_LCD_GetBackColor());
    BSP_LCD_FillCircle(this->newPos.x, this->newPos.y, this->newRadius);
}
