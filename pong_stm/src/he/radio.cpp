#include "he/radio.hpp"

HE::Radio::Radio() : timer() {
    NRF24_begin(GPIOC, Radio_CSN_Pin, Radio_CE_Pin, hspi1);
    NRF24_setAutoAck(this->autoAck);
    NRF24_setChannel(this->channel);
    NRF24_setDataRate(this->speed);
    NRF24_setPayloadSize(this->payloadSize);
    NRF24_setPALevel(RF24_PA_0dB);
    NRF24_enableAckPayload();
    NRF24_setRetries(5, 3);
    //nrf24_DebugUART_Init(huart2);
    //printRadioSettings();
}

HE::Radio::Response HE::Radio::getContrInfo() {
    //NRF24_stopListening();
    //NRF24_openWritingPipe(this->TXAddr1);
    //NRF24_write(this->writeBuf, 32);
    //NRF24_read(this->readBuf[0], this->payloadSize);
    
    
    HE::Radio::Response r;
    r.accContr1 = {0.0f, 0.0f};
    r.accContr2 = {0.0f, 0.0f};
    r.startContr1 = false;
    r.startContr2 = false;

    bool contrResponse1 = false;
    NRF24_stopListening();
    NRF24_openWritingPipe(this->TXAddr1);
    if (NRF24_write(this->writeBuf, this->payloadSize)) {
        if (NRF24_isAckPayloadAvailable()) {
            NRF24_read(this->readBuf[0], this->payloadSize);
            contrResponse1 = true;
        }
    }

    bool contrResponse2 = false;
    NRF24_stopListening();
    NRF24_openWritingPipe(this->TXAddr2);
    if (NRF24_write(this->writeBuf, this->payloadSize)) {
        if (NRF24_isAckPayloadAvailable()) {
            NRF24_read(this->readBuf[1], this->payloadSize);
            contrResponse2 = true;
        }
    }

    if (contrResponse1) {
        HE::Radio::ResponseOneContr r1;
        memcpy(&r1, this->readBuf[0], sizeof(HE::Radio::ResponseOneContr));
        r.accContr1 = {(float)r1.accX, (float)r1.accY};
        r.startContr1 = r1.startContr;
    }

    if (contrResponse2) {
        HE::Radio::ResponseOneContr r2;
        memcpy(&r2, this->readBuf[1], sizeof(HE::Radio::ResponseOneContr));
        r.accContr2 = {(float)r2.accX, (float)r2.accY};
        r.startContr2 = r2.startContr;
    }

    

    return r;
    
}