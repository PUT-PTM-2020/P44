#include "he/buttons.hpp"

bool HE::Buttons::statusWindPlus() {
    if (HAL_GPIO_ReadPin(Button_4_GPIO_Port, Button_4_Pin) == GPIO_PIN_RESET) return true;
    else return false;
}

bool HE::Buttons::statusWindMinus() {
    if (HAL_GPIO_ReadPin(Button_3_GPIO_Port, Button_3_Pin) == GPIO_PIN_RESET) return true;
    else return false;
}

bool HE::Buttons::statusGravPlus() {
    if (HAL_GPIO_ReadPin(Button_2_GPIO_Port, Button_2_Pin) == GPIO_PIN_RESET) return true;
    else return false;
}

bool HE::Buttons::statusGravMinus() {
    if (HAL_GPIO_ReadPin(Button_1_GPIO_Port, Button_1_Pin) == GPIO_PIN_RESET) return true;
    else return false;
}

bool HE::Buttons::statusAirDensPlus() {
    if (HAL_GPIO_ReadPin(Button_7_GPIO_Port, Button_7_Pin) == GPIO_PIN_RESET) return true;
    else return false;
}

bool HE::Buttons::statusAirDensMinus() {
    if (HAL_GPIO_ReadPin(Button_6_GPIO_Port, Button_6_Pin) == GPIO_PIN_RESET) return true;
    else return false;
}

bool HE::Buttons::statusReset() {
    if (HAL_GPIO_ReadPin(Button_5_GPIO_Port, Button_5_Pin) == GPIO_PIN_RESET) return true;
    else return false;
}