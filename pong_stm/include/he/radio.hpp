#include "includes.hpp"
#include "ge/vector2.hpp"
#include "spi.h"
#include "usart.h"
#include "main.h"
extern "C" {
#include "MY_NRF24.h"
}

namespace HE {

class Radio { 
private:
    const bool autoAck = false;
    const uint8_t channel = 52;
    const rf24_datarate_e speed = RF24_1MBPS;
    const uint8_t payloadSize = 32; 
    const uint64_t TXAddr = 0x11223344AA;
    const uint64_t RXAddr = 0x11223344AB;
    const char request[32] = "GIVE";

public:
    Radio();
    std::pair<GE::Vector2f, GE::Vector2f> getControllersAcc();


};

}