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

};
