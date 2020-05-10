#include "he/debug.hpp"

void HE::Debug::sendUART(char* buf) {
    HAL_UART_Transmit_IT(&huart2, (uint8_t*)buf, strlen(buf));
}

void HE::Debug::sendUART(int num) {
    char buf[12];
    sprintf(buf, "%d", num);
    HAL_UART_Transmit_IT(&huart2, (uint8_t*)buf, strlen(buf));
}
