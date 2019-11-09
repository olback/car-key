#include "CKBase.h"

class CKRemote : public CKBase {

public:

    // Constructor
    CKRemote();

    // Setup
    void begin();

    // Lock the car
    void lock();

    // Unlock the car
    void unlock();

};
