#pragma once
#include "i2c.h"
#include "main.h"
extern "C" {
#include "ssd1306.h" //Biblioteka napisana w C, więc trzeba użyć extern "C"
}

namespace HE {

//Klasa do obsługi małego wyświetlacza oled
class Oled {
private:
    const FontDef font = Font_11x18; //Wybór czcionki
public:
    Oled();
    void writeLine(uint8_t line, char* text);
    void display();
};

}