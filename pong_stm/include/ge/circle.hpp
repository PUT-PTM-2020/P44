#pragma once
#include "includes.hpp"
#include "shape.hpp"
#include "stm32_adafruit_lcd.h"

namespace GE
{

class Circle : public Shape {
private:
    uint16_t newRadius;
    uint16_t oldRadius;

public:
    Circle(uint16_t radius, uint16_t posX, uint16_t posY, uint16_t color = GE::Color::white);
    
    uint16_t getRadius();
    
    void setRadius(uint16_t radius);
    
    void draw();

    ~Circle();
};

}