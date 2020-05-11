#include "includes.hpp"
#include "ge/vector2.hpp"
#include "spi.h"
#include "main.h"
extern "C" {
#include "MY_NRF24.h"
}

namespace HE {

class Radio { 
private:

    const bool autoAck = true;
    const uint8_t channel = 52;
    const rf24_datarate_e speed = RF24_1MBPS;
    const rf24_pa_dbm_e powerLevel = RF24_PA_0dB;
    const uint8_t payloadSize = 32;
    const uint8_t delayBetweenTries = 5;
    const uint8_t numOfTries = 3;
    const uint64_t TXAddr1 = 0x11223344AA;
    const uint64_t TXAddr2 = 0x11223344BB;

    const char writeBuf[32] = "GIVE";
    char readBuf[2][32];

    struct ResponseOneContr {
        int16_t accX;
        int16_t accY;
        int16_t startContr;
        int16_t checksum;
    };

public:

    struct Response {
        GE::Vector2f accContr1;
        GE::Vector2f accContr2;
        bool startContr1;
        bool startContr2;
    };

    Radio();
    Response getContrInfo();

};

}