#include "he/radio.hpp"

HE::Radio::Radio() {
    NRF24_begin(GPIOC, Radio_CSN_Pin, Radio_CE_Pin, hspi1);
}

std::pair<GE::Vector2f, GE::Vector2f> HE::Radio::getControllersAcc() {
    NRF24_stopListening();
    NRF24_setAutoAck(this->autoAck);
    NRF24_openWritingPipe(this->TXAddr);
    NRF24_setChannel(this->channel);
    NRF24_setDataRate(this->speed);
    NRF24_setPayloadSize(this->payloadSize);
    NRF24_write(this->request, this->payloadSize);

    

}