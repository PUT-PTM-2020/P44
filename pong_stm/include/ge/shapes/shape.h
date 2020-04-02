#include "vector2.h"

namespace GE
{

class Shape {
private:
    GE::Vector2i pos;
    uint16_t color;
    
public:
    Shape(uint16_t posX, uint16_t posY, uint16_t color);
    Shape(GE::Vector2i pos, uint16_t color);

    uint16_t getPosX();
    uint16_t getPosY();
    GE::Vector2i getPos();

    void setPosX(uint16_t posX);
    void setPosY(uint16_t posY);
    void setPos(uint16_t posX, uint16_t posY);
    void setPos(GE::Vector2i pos);

    void move(uint16_t x, uint16_t y);
    void move(GE::Vector2i v);

    void setColor(uint16_t color);

    void draw();
};
    
}