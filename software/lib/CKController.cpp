#include "CKController.h"

CKController::CKController() {}

void CKController::begin() {

    // Base init
    init();

    // Configure radio to listen
    radio.openReadingPipe(0, ADDRESS);
    radio.startListening();

    // Set PA level to high, this should be higher than on the remote!
    radio.setPALevel(RF24_PA_MIN);

    Serial.println("Controller started!");

}

