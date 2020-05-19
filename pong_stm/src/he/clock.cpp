#include "he/clock.hpp"

HE::Clock::Clock() : creationTime(HAL_GetTick()) {}

//Wartość czasu jest zwracana w postaci sekund z dokładnością do 1ms (czyli np. jest zwracane 2.371 s)
float HE::Clock::getTime() { return ((float)(HAL_GetTick() - this->creationTime) / 1000.0f); }

//Resetuj licznik
void HE::Clock::reset() { this->creationTime = HAL_GetTick(); }

