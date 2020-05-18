#pragma once
#include "usart.h"
#include "includes.hpp"

//Klasa statyczna do debugowania, na razie obsługuje jedynie UART
namespace HE {

class Debug {
public:
    static void sendUART(char* buf);
    static void sendUART(int num);
    static void sendUART(float num);
};

}