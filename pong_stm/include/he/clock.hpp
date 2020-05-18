#pragma once
#include "includes.hpp"
#include "main.h"

namespace HE {


//Klasa obiektu obsługującego czas (a raczej licznik czasu od czasu użycia reset() lub utworzenia obiektu)
//Wykorzystuje funkcję HAL_GetTick() do liczenia czasu
class Clock {
private:
    uint32_t creationTime;
public:
    Clock();
    float getTime();
    void reset();
};





}