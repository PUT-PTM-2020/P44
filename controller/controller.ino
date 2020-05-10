#include <Wire.h>
#include <SPI.h>
#include "RF24.h"
#include "nRF24L01.h"
#include "MPU6050.h"

#define CE_PIN 0 //Fizyczny pin 2
#define CSN_PIN 1 //Fizyczny pin 3
#define IRQ_PIN 2 //Fizyczny pin 4

struct ResponseOneContr {
  uint16_t accX;
  uint16_t accY;
  bool startContr;
};

ResponseOneContr response;

MPU6050 mpu;
Vector normAccel;

RF24 radio(CE_PIN, CSN_PIN);
const byte RXAddr[6] = {0xAA, 0x44, 0x33, 0x22, 0x11};
const byte TXAddr[6] = {0xBB, 0x44, 0x33, 0x22, 0x11};

void respond() {
  radio.stopListening();
  response.startContr = false;
  radio.write((char*)&response, 32);
  radio.startListening();
}


void setup() {
  mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
  radio.begin();
  radio.setAutoAck(false);
  radio.setChannel(52);
  radio.setPayloadSize(32);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0, RXAddr);
  radio.openWritingPipe(TXAddr);
  radio.startListening();
  attachInterrupt(IRQ_PIN, respond, FALLING);
}

void loop() {
  normAccel = mpu.readNormalizeAccel();
  response.accX = (int)normAccel.XAxis;
  response.accY = (int)normAccel.ZAxis - 10;
}
