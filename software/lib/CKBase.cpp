#include "CKBase.h"

CKBase::CKBase() {}

void CKBase::init() {

    // Begin serial
    Serial.begin(115200);

    // Begin radio
    radio.begin();
    radio.setAutoAck(true);
    radio.setRetries(4, 15);
    radio.setDataRate(RF24_250KBPS);

    // Configure interrupt pin
    pinMode(INTERRUPT_PIN, INPUT_PULLUP);

}

void CKBase::_debug() {

    Serial.println("-- Radio Info --");
    radio.printDetails();
    Serial.println();

    Serial.println("-- CKBase Info --");
    Serial.println("<add output>");

}

bool CKBase::write(const void *msg, uint8_t length) {

    return radio.write(msg, length);

}

bool CKBase::read(void *msg, uint8_t length) {

    radio.read(msg, length);

    return true;

}

void CKBase::attachInterrupt(void (*func)(void)) {

    ::attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), func, LOW);

}
