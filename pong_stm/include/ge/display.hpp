#pragma once
#include "stm32_adafruit_lcd.h"
#include "colors.hpp"

namespace GE 
{

//Klasa zarządzająca ekranem
class Display {
public:
    Display();
    uint16_t getSizeX();
    uint16_t getSizeY();
    uint16_t getBackColor();
    void setBackColor(uint16_t color);
    void turnOff();
    void turnOn();
    void clear();
};

} 
