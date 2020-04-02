#include "stm32_adafruit_lcd.h"
#include "vector2.h"

namespace GE 
{

class Display {
public:
    Display();
    uint16_t getSizeX();
    uint16_t getSizeY();
    GE::Vector2i getSize();
    uint16_t getBackColor();
    void setBackColor(uint16_t color);
    void turnOff();
    void turnOn();
    void clear();
};

} 
