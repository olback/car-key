#include <CKController.h>

#ifdef DEBUG
  #include <printf.h>
#endif

CKController controller;

void setup() {

  #ifdef DEBUG
    printf_begin();
  #endif

  controller.begin();
  controller.attachInterrupt(recvMsg);

  controller._debug();

}

void loop() {

  switch(Serial.read()) {

    case 'd': {
      Serial.println("Debug!");
      break;
    }

    default: {
      Serial.println("No data...");
      delay(1000);
    }

  }

}

void recvMsg() {

  char text[32] = {0};
  controller.readMsg(&text, sizeof(text));
  Serial.print("Recv: ");
  Serial.println(text);

}
