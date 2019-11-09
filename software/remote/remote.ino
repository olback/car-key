#ifndef ARDUINO
    #define ARDUINO
#endif

#include <CKRemote.h>

CKRemote remote;

void setup() {

    // Only for testing on Leonardo
    while (!Serial) {
        Serial.begin(115200);
    }

    remote.begin();

}

void loop() {

    const char a[32] = "12000000000000000000000000000034";
    Serial.print("Sending... ");
    bool txs = remote.write(&a, sizeof(a));
    if (txs) {
        Serial.println("success");
    } else {
        Serial.println("failed");
    }

    delay(5000);

}
