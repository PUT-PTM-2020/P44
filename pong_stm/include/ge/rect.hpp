#pragma once
#include "includes.hpp"
#include "shape.hpp"
#include "stm32_adafruit_lcd.h"

namespace GE
{

//Klasa prostokątu, dziedziczy z Shape
class Rect : public Shape {
private:
    uint16_t newSizeX;
    uint16_t newSizeY;
    uint16_t oldSizeX;
    uint16_t oldSizeY;
public:
    Rect(uint16_t sizeX, uint16_t sizeY, uint16_t posX, uint16_t posY, uint16_t color = GE::Color::white);
    
    uint16_t getSizeX();
    uint16_t getSizeY();
    
    void setSizeX(uint16_t sizeX);
    void setSizeY(uint16_t sizeY);
    
    void draw();

    ~Rect();
};

}