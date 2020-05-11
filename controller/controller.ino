#include <Wire.h>
#include <SPI.h>
#include "RF24.h"
#include "nRF24L01.h"
#include "MPU6050.h"

#define CE_PIN 0 //Fizyczny pin 2
#define CSN_PIN 1 //Fizyczny pin 3
#define IRQ_PIN 2 //Fizyczny pin 4
#define B1_PIN 3 //Fizyczny pin 5

struct ResponseOneContr {
  int16_t accX;
  int16_t accY;
  int16_t startContr;
  int16_t checksum;
};

ResponseOneContr response;

MPU6050 mpu;
Vector normAccel;

RF24 radio(CE_PIN, CSN_PIN);
const byte RXAddr1[6] = {0xAA, 0x44, 0x33, 0x22, 0x11};

char readBuf[32];

void respond() {
  if (radio.available()) {
    radio.read(readBuf, 32);
  }
}

void setup() {
  pinMode(B1_PIN, INPUT_PULLUP);
  //Serial.begin(9600);
  mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
  radio.begin();
  radio.setAutoAck(true);
  radio.setChannel(52);
  radio.setPayloadSize(32);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MIN);
  radio.enableAckPayload();
  radio.openReadingPipe(1, RXAddr1);
  radio.startListening();
  attachInterrupt(IRQ_PIN, respond, FALLING);
  
}

void loop() {
  normAccel = mpu.readNormalizeAccel();
  response.accX = (int16_t)normAccel.XAxis;
  response.accY = (int16_t)normAccel.ZAxis - 10;
  if (digitalRead(B1_PIN) == LOW) response.startContr = true;
  else response.startContr = false;

  response.checksum = response.accX + response.accY + response.startContr;
  
  radio.writeAckPayload(1, (char*)&response, 32);
  //Serial.print(" Xnorm = ");
  //Serial.print(response.accX);
  //Serial.print(" Ynorm = ");
  //Serial.println(response.accY);

}
