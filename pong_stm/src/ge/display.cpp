#include "ge/display.hpp"

void GE::Display::init() { BSP_LCD_Init(); }

uint16_t GE::Display::getSizeX() { return BSP_LCD_GetXSize(); }

uint16_t GE::Display::getSizeY() { return BSP_LCD_GetYSize(); }

uint16_t GE::Display::getBackColor() { return BSP_LCD_GetBackColor(); };

void GE::Display::setBackColor(uint16_t color) { BSP_LCD_SetBackColor(color); }

void GE::Display::turnOff() { BSP_LCD_DisplayOff(); }

void GE::Display::turnOn() { BSP_LCD_DisplayOn(); }

void GE::Display::clear() { BSP_LCD_Clear(BSP_LCD_GetBackColor()); }