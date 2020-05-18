#pragma once
#include "includes.hpp"
#include "ge/vector2.hpp"
#include "spi.h"
#include "main.h"
extern "C" {
#include "MY_NRF24.h" //Biblioteka napisana w C, więc trzeba użyć extern "C"
}

namespace HE {

//Klasa do obsługi komunikacji radiowej między STM a kontrolerami
class Radio { 
private:

    //Ustawione parametry do komunikacji
    const bool autoAck = true; //Odpowiedź od kontrolerów wysyłana jest w postaci ACK
    const uint8_t channel = 52; //Kanał 52
    const rf24_datarate_e speed = RF24_1MBPS; //Prędkość 1 Mbps
    const rf24_pa_dbm_e powerLevel = RF24_PA_0dB; //Maksymalna siła anteny nadawczej
    const uint8_t payloadSize = 32; //Domyślna wielkość pakietu - 32 bajty
    const uint8_t delayBetweenTries = 5; //Czekaj 5μs na odpowiedź
    const uint8_t numOfTries = 3; //Próbuj wysłać pakiet do 3 razy (jeśli nie było odpowiedzi ACK)
    const uint64_t TXAddr1 = 0x11223344AA; //Adres pierwszego kontrolera
    const uint64_t TXAddr2 = 0x11223344BB; //Adres drugiego kontrolera

    const char writeBuf[32] = "GIVE"; //Wysyłany komunikat do kontrolerów kiedy STM chce uzyskać od nich odpowiedź z aktualnym przyspieszeniem
    char readBuf[2][32]; //Bufer do odczytów

    //Struktura znajdująca się w odpowiedzi od kontrolera
    struct ResponseOneContr {
        int16_t accX;
        int16_t accY;
        int16_t startContr;
        int16_t checksum;
    };

public:

    //Struktura z danymi z obu kontrolerów zwracana przez getContrInfo();
    struct Response {
        GE::Vector2f accContr1;
        GE::Vector2f accContr2;
        bool startContr1;
        bool startContr2;
    };

    Radio();
    Response getContrInfo(); //Wyślij prośbę o dane do kontrolerów i zwróć odpowiedź
};

}