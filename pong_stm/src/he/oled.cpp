#include "he/oled.hpp"

//Inicjalizacja w konstruktorze
HE::Oled::Oled() { ssd1306_Init(); }

//Wpisz coś w wybraną linie (ilość dostępnych lini zalezy od wysokości wybranej czcionki)
void HE::Oled::writeLine(uint8_t line, char* text) {
    ssd1306_SetCursor(0, line * this->font.FontHeight);
    ssd1306_WriteString(text, this->font, White);
}

//Wyświetl wpisane do bufora rzeczy
void HE::Oled::display() { ssd1306_UpdateScreen(); }