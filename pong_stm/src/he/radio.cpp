#include "he/radio.hpp"

HE::Radio::Radio() : timer() {
    NRF24_begin(GPIOC, Radio_CSN_Pin, Radio_CE_Pin, hspi1);
    NRF24_setAutoAck(this->autoAck);
    NRF24_setChannel(this->channel);
    NRF24_setDataRate(this->speed);
    NRF24_setPayloadSize(this->payloadSize);
    NRF24_setPALevel(RF24_PA_m18dB);
}

HE::Radio::Response HE::Radio::getContrInfo() {
    NRF24_stopListening();
    NRF24_openWritingPipe(this->TXAddr);
    NRF24_write(this->writeBuf, this->payloadSize);
    NRF24_openReadingPipe(1, this->RXAddr);
    NRF24_openReadingPipe(2, this->RXAddr);
    
    float startTime = timer.getTime();
    int numberOfResponses = 0;
    HE::Radio::Response r;

    while ((timer.getTime() - startTime < this->waitTime) && (numberOfResponses < 2)) {
        if (NRF24_read(this->readBuf[numberOfResponses], this->payloadSize)) numberOfResponses++;
    }

    if (numberOfResponses == 2) {
        HE::Radio::ResponseOneContr r1, r2;
        memcpy(&r1, this->readBuf[0], sizeof(HE::Radio::ResponseOneContr));
        memcpy(&r2, this->readBuf[1], sizeof(HE::Radio::ResponseOneContr));

        r.accContr1 = {(float)r1.accX, (float)r1.accY};
        r.startContr1 = r1.startContr;
        r.accContr2 = {(float)r2.accX, (float)r2.accY};
        r.startContr2 = r2.startContr;

    } else {
        r.accContr1 = {0.0f, 0.0f};
        r.accContr2 = {0.0f, 0.0f};
        r.startContr1 = false;
        r.startContr2 = false;
    }

    return r;
}