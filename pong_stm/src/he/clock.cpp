#include "he/clock.hpp"
#include "stm32f4xx_hal.h"

HE::Clock::Clock() : creationTime(HAL_GetTick()) {}

float HE::Clock::getTime() { return ((float)(this->creationTime - HAL_GetTick()) / 1000.0f); }

void HE::Clock::reset() { this->creationTime = HAL_GetTick(); }

