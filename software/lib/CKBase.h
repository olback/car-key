#ifndef ARDUINO
  #define ARDUINO
#endif

#include <AESLib.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <EEPROM.h>

enum Action {
    Lock,
    Unlock
};

struct CKData {
    uint32_t id;
    Action action;
};

class CKBase {

public:

    // Debug function, print state to serial
    void _debug();

    // Configure radio, start serial...
    void init();

    // Set key. This writes to the EEPROM
    void setKey(uint8_t key[32]);

    // Encrypts and sends a message
    bool sendMsg(void *msg, uint8_t length);

    // Decrypts a recieved message
    void readMsg(void *msg, uint8_t length);

    // Increase ID by one
    void increaseId();

    // Set an ID
    void setId(uint32_t id);

    // Attach interrupt
    void attachInterrupt(void (*func)(void));

protected:

    CKBase();

    RF24 radio = RF24(9, 8);

    const uint8_t INTERRUPT_PIN = 2;
    const uint8_t COUNETR_ADDR = 0;
    const uint8_t KEY_ADDR = 4;
    // const uint8_t ADDRESS[5] = { 'C', 'K', 'A', 'D', 'R' };
    const uint8_t ADDRESS[5] = { '0', '0', '0', '0', '1' };

    // Encrypt msg with key from readKey()
    void encrypt(uint8_t *msg);

    // Decrypt msg with key from readKey()
    void decrypt(uint8_t *msg);

    // Read key from EEPROM
    void readKey(uint8_t key[32]);

};
