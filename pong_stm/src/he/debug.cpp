#include "he/debug.hpp"

//Wysyłanie tekstu
void HE::Debug::sendUART(char* buf) {
    HAL_UART_Transmit(&huart2, (uint8_t*)buf, strlen(buf), 10);
}

//Wysyłanie int (tak aby był widoczny jako tekst)
void HE::Debug::sendUART(int num) {
    char buf[12];
    sprintf(buf, "%d", num);
    HAL_UART_Transmit(&huart2, (uint8_t*)buf, strlen(buf), 10);
}

//Wysyłanie float (tak aby był widoczny jako tekst)
void HE::Debug::sendUART(float num) {
    char buf[64];
    sprintf(buf, "%f", num);
    HAL_UART_Transmit(&huart2, (uint8_t*)buf, strlen(buf), 10);
}
