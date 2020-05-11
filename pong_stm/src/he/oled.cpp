#include "he/oled.hpp"

HE::Oled::Oled() {
    ssd1306_Init();
}

void HE::Oled::writeLine(uint8_t line, char* text) {
    ssd1306_SetCursor(0, line * this->font.FontHeight);
    ssd1306_WriteString(text, this->font, White);
}

void HE::Oled::display() {
    ssd1306_UpdateScreen();
}