#include "includes.hpp"
#include "ge/vector2.hpp"
#include "he/clock.hpp"
#include "spi.h"
#include "usart.h"
#include "main.h"
extern "C" {
#include "MY_NRF24.h"
}

namespace HE {

class Radio { 
private:

    struct ResponseOneContr {
        uint16_t accX;
        uint16_t accY;
        bool startContr;
    };

    const bool autoAck = false;
    const uint8_t channel = 52;
    const rf24_datarate_e speed = RF24_1MBPS;
    const uint8_t payloadSize = 32;
    const uint64_t TXAddr = 0x11223344AA;
    const uint64_t RXAddr = 0x11223344BB;
    const char writeBuf[32] = "GIVE";
    HE::Clock timer;
    const float waitTime = 0.005f;
    char readBuf[2][32];

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