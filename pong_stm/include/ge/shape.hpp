#pragma once
#include "includes.hpp"
#include "vector2.hpp"
#include "colors.hpp"

namespace GE
{

class Shape {
protected:
    Vector2i newPos;
    Vector2i oldPos;
    uint16_t color;
    
public:
    Shape(uint16_t posX, uint16_t posY, uint16_t color = GE::Color::white);

    uint16_t getPosX();
    uint16_t getPosY();
    Vector2i getPos();

    void setPosX(uint16_t posX);
    void setPosY(uint16_t posY);
    void setPos(uint16_t posX, uint16_t posY);
    void setPos(Vector2i& pos);

    void move(uint16_t x, uint16_t y);
    void move(Vector2i& v);

    void setColor(uint16_t color);

    virtual void draw() = 0;
};
    
}