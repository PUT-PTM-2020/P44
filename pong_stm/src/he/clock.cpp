#include "he/clock.hpp"

HE::Clock::Clock() : creationTime(HAL_GetTick()) {}

float HE::Clock::getTime() { return ((float)(HAL_GetTick() - this->creationTime) / 1000.0f); }

void HE::Clock::reset() { this->creationTime = HAL_GetTick(); }

