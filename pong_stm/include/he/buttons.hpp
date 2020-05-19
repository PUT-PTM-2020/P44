#pragma once
#include "main.h"
#include "gpio.h"

namespace HE {

//Statycznka klasa obsługująca przyciski do zmiany parametrów fizycznych
//Przyciski są podłączne w konfiguracji pull-up 
class Buttons {
public:
    //Wykrywanie aktualnego naciskania danego przycisku
    static bool statusWindPlus();
    static bool statusWindMinus();
    static bool statusGravPlus();
    static bool statusGravMinus();
    static bool statusAirDensPlus();
    static bool statusAirDensMinus();
    static bool statusReset();
};

}