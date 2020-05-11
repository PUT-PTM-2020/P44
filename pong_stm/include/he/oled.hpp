#include "i2c.h"
#include "main.h"
extern "C" {
#include "ssd1306.h"
}

namespace HE {

class Oled {
private:
    const FontDef font = Font_11x18;
public:
    Oled();
    void writeLine(uint8_t line, char* text);
    void display();
};

}