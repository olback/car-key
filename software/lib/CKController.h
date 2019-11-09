#include "CKBase.h"

class CKController : public CKBase {

public:

    // Constructor
    CKController();

    // Setup
    void begin();

    // Verify ID
    bool verify(uint32_t id);

    // Lock the car
    void lock();

    // Unlock the car
    void unlock();


private:

    const uint8_t S_UNLOCK_PIN = 7;
    const uint8_t S_LOCK_PIN = 6;
    const uint8_t S_POWER_PIN = 5;
    const uint8_t V_SENSE_PIN = 14;

};
