#pragma once
#include "main.h"
#include "gpio.h"

namespace HE {

class Buttons {
public:
    static bool statusWindPlus();
    static bool statusWindMinus();
    static bool statusGravPlus();
    static bool statusGravMinus();
    static bool statusAirDensPlus();
    static bool statusAirDensMinus();
    static bool statusReset();
};

}