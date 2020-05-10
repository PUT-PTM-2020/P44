#include "he/debug.hpp"

void HE::Debug::sendUART(char* buf) {
    HAL_UART_Transmit_IT(&huart2, (uint8_t*)buf, sizeof((uint8_t*)buf));
}
