#include "includes.hpp"

namespace HE {

class Clock {
private:
    uint32_t creationTime;
public:
    Clock();
    float getTime();
    void reset();
};





}