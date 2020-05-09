#pragma once
#include "includes.hpp"
#include "main.h"

namespace HE {

class Clock {
private:
    uint32_t creationTime;
public:
    Clock();
    float getTime();
    void reset();
};





}