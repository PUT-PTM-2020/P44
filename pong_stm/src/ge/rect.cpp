#include "ge/rect.hpp"

GE::Rect::Rect(uint16_t sX, uint16_t sY, uint16_t pX, uint16_t pY, uint16_t c) : Shape(pX, pY, c), sizeX(sX), sizeY(sY) {}

uint16_t GE::Rect::getSizeX() { return this->sizeX; }

uint16_t GE::Rect::getSizeY() { return this->sizeY; }

void GE::Rect::setSizeX(uint16_t sX) { this->sizeX = sX; }

void GE::Rect::setSizeY(uint16_t sY) { this->sizeY = sY; }

void GE::Rect::draw() {
    BSP_LCD_SetTextColor(this->color);
    BSP_LCD_FillRect(this->pos.x, this->pos.y, this->sizeX, this->sizeY);
}

