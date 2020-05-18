#include "ge/rect.hpp"

GE::Rect::Rect(uint16_t sX, uint16_t sY, uint16_t pX, uint16_t pY, uint16_t c) : Shape(pX, pY, c), newSizeX(sX), newSizeY(sY), oldSizeX(sX), oldSizeY(sY) {}

uint16_t GE::Rect::getSizeX() { return this->newSizeY; }

uint16_t GE::Rect::getSizeY() { return this->newSizeX; }

void GE::Rect::setSizeX(uint16_t sX) { 
    this->oldSizeX = this->newSizeX;
    this->newSizeX = sX; 
}

void GE::Rect::setSizeY(uint16_t sY) { 
    this->oldSizeY = this->newSizeY;
    this->newSizeY = sY; 
}

//Implementacja mechanizmu starej i nowej pozycji 
//Przed rysowaniem obiektu w nowej pozycji obiekt z starej pozycji jest usuwany (tzw. zostaje zastąpiony obiektem o kolorze tła)
//Dzieje się to tylko wtedy kiedy obiekt był przmieszczony lub jego wielkość została zmieniona (stara wielkość też jest zapisywana)
void GE::Rect::draw() {
    if (newPos != oldPos || newSizeX != oldSizeX || newSizeY != oldSizeY) {
        BSP_LCD_SetTextColor(BSP_LCD_GetBackColor());
        BSP_LCD_FillRect(this->oldPos.x, this->oldPos.y, this->oldSizeX, this->oldSizeX);
    }
    BSP_LCD_SetTextColor(this->color);
    BSP_LCD_FillRect(this->newPos.x, this->newPos.y, this->newSizeX, this->newSizeY);
}

GE::Rect::~Rect() {
    BSP_LCD_SetTextColor(BSP_LCD_GetBackColor());
    BSP_LCD_FillRect(this->newPos.x, this->newPos.y, this->newSizeX, this->newSizeX);
}
