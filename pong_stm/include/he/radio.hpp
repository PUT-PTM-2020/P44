#include "includes.hpp"
#include "ge/vector2.hpp"
#include "he/clock.hpp"
#include "he/debug.hpp"
#include "spi.h"
#include "main.h"
#include "usart.h"
extern "C" {
#include "MY_NRF24.h"
}

namespace HE {

class Radio { 
private:

    const bool autoAck = true;
    const uint8_t channel = 52;
    const rf24_datarate_e speed = RF24_1MBPS;
    const uint8_t payloadSize = 32;
    const uint64_t TXAddr1 = 0x11223344AA;
    const uint64_t TXAddr2 = 0x11223344BB;
    
    const float waitTime = 0.003f;
    const char writeBuf[32] = "GIVE";
    char readBuf[2][32];

    HE::Clock timer;

    struct ResponseOneContr {
        int16_t accX;
        int16_t accY;
        bool startContr;
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