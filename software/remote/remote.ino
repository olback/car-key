#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 8);

const byte address[6] = "00001";

void setup() {

  while (!Serial) {
    Serial.begin(115200);
  }

  // Serial.begin(115200);

  radio.begin();
  radio.setAutoAck(1);
  radio.setRetries(0, 15);
  radio.openWritingPipe(address);
  radio.stopListening();

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {

    while (Serial.available()) {
      Serial.read();
      delay(1);
    }

    Serial.println("Sending...");

    const char text[] = "Hello!";
    byte a = radio.write(&text, sizeof(text));
    Serial.println(a);

    delay(1000);
  
  }

}
