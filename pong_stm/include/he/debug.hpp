#pragma once

#include "usart.h"
#include "includes.hpp"

namespace HE {

class Debug {
public:
    static void sendUART(char* buf);
    static void sendUART(int num);
};

}