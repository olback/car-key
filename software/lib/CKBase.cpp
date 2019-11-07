#include "CKBase.h"

CKBase::CKBase() {}

void CKBase::init() {

    // Begin serial
    Serial.begin(115200);

    // Begin radio
    radio.begin();
    radio.setAutoAck(1);
    radio.enableDynamicAck();
    radio.setRetries(1, 15);
    radio.setDataRate(RF24_250KBPS);

    // Configure interrupt pin
    pinMode(INTERRUPT_PIN, INPUT_PULLUP);

}

void CKBase::_debug() {

    #ifdef DEBUG
        Serial.println("-- Radio Info --");
        radio.printDetails();
        Serial.println();
    #endif

    Serial.println("-- CKBase Info --");
    Serial.println("<add output>");

}

void CKBase::readMsg(void *msg, uint8_t length) {

    radio.read(msg, length);

}

void CKBase::attachInterrupt(void (*func)(void)) {

    ::attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), func, LOW);

}
