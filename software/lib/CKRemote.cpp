#include "CKRemote.h"

CKRemote::CKRemote() {}

void CKRemote::begin() {

    // Base init
    init();

    // Configure radio to listen
    radio.openWritingPipe(ADDRESS);
    radio.stopListening();

    // Set PA level to low, this should be lower than on the controller!
    radio.setPALevel(RF24_PA_MIN);

    Serial.println("Remote started");

}

