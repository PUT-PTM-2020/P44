#pragma once
#include "includes.hpp"
#include "vector2.hpp"
#include "colors.hpp"

namespace GE
{

//Klasa wirtualna z której dziedziczą klasy obiektów, które mają być wyświetlane na ekranie
//Stosowany jest mechanizm nowej i starej pozycji - przy rysowaniu obiektu na nowej pozycji obiekt z starej jest usuwany - dzięki temu nie trzeba odświerzać co klatkę całego ekranu
class Shape {
protected:
    Vector2i newPos;
    Vector2i oldPos;
    uint16_t color;
    
public:
    Shape(uint16_t posX, uint16_t posY, uint16_t color = GE::Color::white);

    //Pobieranie aktualnej pozycji x, y lub wektora pozycji
    uint16_t getPosX();
    uint16_t getPosY();
    Vector2i getPos();

    //Ustawianie nowej pozycji, można podać parametry oddzielnie lub w wektorze itp.
    void setPosX(uint16_t posX);
    void setPosY(uint16_t posY);
    void setPos(uint16_t posX, uint16_t posY);
    void setPos(Vector2i& pos);

    //Jeśli nie chcemy ustawiać starej pozycji
    void setNewPosOnly(Vector2i& pos);

    //Przemieszczenie zamiast ustawiania nowych pozycji
    void move(uint16_t x, uint16_t y);
    void move(Vector2i& v);

    void setColor(uint16_t color);

    //Do implementacji w dzieciach
    virtual void draw() = 0;
};
    
}