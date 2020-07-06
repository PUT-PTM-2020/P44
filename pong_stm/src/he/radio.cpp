#include "he/radio.hpp"
#include "he/debug.hpp"

//Inicjalizacja radia w konstruktorze, ustawianie parametrów
HE::Radio::Radio() {
    NRF24_begin(GPIOC, Radio_CSN_Pin, Radio_CE_Pin, hspi1);
    NRF24_setAutoAck(this->autoAck);
    NRF24_setChannel(this->channel);
    NRF24_setDataRate(this->speed);
    NRF24_setPayloadSize(this->payloadSize);
    NRF24_setPALevel(this->powerLevel);
    NRF24_setRetries(this->delayBetweenTries, this->numOfTries);
    NRF24_enableAckPayload();

    //Wyczyść bufory radia
    NRF24_flush_rx(); 
    NRF24_flush_tx();
}

//Wyślij prośbę o dane do kontrolerów i zwróć odpowiedź
HE::Radio::Response HE::Radio::getContrInfo() {

    //Wyczyść bufory radia
    NRF24_flush_rx();
    NRF24_flush_tx();
    
    //Zmienne startowe, ustaw domyślne odpowiedzi kontrolerów na 0
    HE::Radio::Response r;
    r.accContr1 = {0.0f, 0.0f};
    r.accContr2 = {0.0f, 0.0f};
    r.startContr1 = false;
    r.startContr2 = false;
    //Wyślij zapytanie do kontrolera 1
    bool contrResponse1 = false;
    NRF24_stopListening();
    NRF24_openWritingPipe(this->TXAddr1); //Ustaw adres do wysyłki
    if (NRF24_write(this->writeBuf, this->payloadSize)) {
        if (NRF24_isAckPayloadAvailable()) { //Jeśli przyszło ACK, odczytaj dane z ACK
            NRF24_read(this->readBuf[0], this->payloadSize);
            contrResponse1 = true;
        }
    }

    //Wyślij zapytanie do kontrolera 2
    bool contrResponse2 = false;
    NRF24_stopListening();
    NRF24_openWritingPipe(this->TXAddr2); //Ustaw adres do wysyłki
    if (NRF24_write(this->writeBuf, this->payloadSize)) {
        if (NRF24_isAckPayloadAvailable()) { //Jeśli przyszło ACK, odczytaj dane z ACK
            NRF24_read(this->readBuf[1], this->payloadSize);
            contrResponse2 = true;
        }
    }

    //Jeśli przyszła odpowiedź z kontrolera 1 - wpisz dane do zwracanej struktury
    if (contrResponse1) {
        HE::Radio::ResponseOneContr r1;
        memcpy(&r1, this->readBuf[0], sizeof(HE::Radio::ResponseOneContr)); //Przekopiuj dane z bufora do miejsca w pamięci w którym znajduje się struktura r1
        if ((r1.accX + r1.accY + r1.startContr) == r1.checksum) { //Sprawdź sumę kontrolną, jeśli się zgadza - wpisz dane do zwracanej przez metodę struktury
            r.accContr1 = {(float)r1.accX * (9.80665f / 4096.0f), (float)r1.accY * (9.80665f / 4096.0f)};
            r.startContr1 = (bool)r1.startContr;
        }
    }

    //Jeśli przyszła odpowiedź z kontrolera 2 - wpisz dane do zwracanej struktury
    if (contrResponse2) {
        HE::Radio::ResponseOneContr r2;
        memcpy(&r2, this->readBuf[1], sizeof(HE::Radio::ResponseOneContr)); //Przekopiuj dane z bufora do miejsca w pamięci w którym znajduje się struktura r2
        if ((r2.accX + r2.accY + r2.startContr) == r2.checksum) { //Sprawdź sumę kontrolną, jeśli się zgadza - wpisz dane do zwracanej przez metodę struktury
            r.accContr2 = {(float)r2.accX * (9.80665f / 4096.0f), (float)r2.accY * (9.80665f / 4096.0f)};
            r.startContr2 = (bool)r2.startContr;
        }
    }

    return r; //Zwróć strukturę odpowiedzi kontrolerów
}