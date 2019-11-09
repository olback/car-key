#include <CKController.h>

// #define DEBUG

#ifdef DEBUG
  #include <printf.h>
#endif

CKController controller;

void setup() {

    controller.begin();

    #ifdef DEBUG
        printf_begin();
        controller._debug();
    #endif

    controller.attachInterrupt(recvMsg);

}

void loop() {

    // Check voltage

    // Delay
    delay(1000);

}

void recvMsg() {

    char a[32] = {0};

    controller.read(&a, sizeof(a));
    Serial.print("Recv: ");
    Serial.println(a);

}
