#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <AESLib.h>

const byte INT_PIN = 2;
const byte KEY[32] = u8"00000000000000000000000000000000";
const byte ADDRESS[6] = "00001";

RF24 radio(9, 8);

void setup() {

  Serial.begin(115200);
  Serial.println("Hello from rx!");

  radio.begin();
  radio.setAutoAck(1);
  radio.setRetries(0, 15);
  radio.openReadingPipe(0, ADDRESS);
  radio.startListening();

  pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), recvMsg, LOW);

  /* char *data = "Hello!";
  Serial.println(data);
  aes256_enc_single(KEY, data);
  Serial.println(data);
  aes256_dec_single(KEY, data);
  Serial.println(data); */

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
  radio.read(&text, sizeof(text));
  Serial.print("Recv: ");
  Serial.println(text);

}
