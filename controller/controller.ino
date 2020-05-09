#include <Wire.h>
#include <SPI.h>
#include "RF24.h"
#include "nRF24L01.h"
#include "MPU6050.h"
//#include "printf.h"

#define CE_PIN 0 //Fizyczny pin 2
#define CSN_PIN 1 //Fizyczny pin 3
#define IRQ_PIN 2 //Fizyczny pin 4

struct ResponseOneContr {
  uint16_t accX;
  uint16_t accY;
  bool startContr;
};

MPU6050 mpu;
/*
RF24 radio(CE_PIN, CSN_PIN);
const byte RXAddr[6] = {0xAA, 0x44, 0x33, 0x22, 0x11};
const byte TXAddr[6] = {0xBB, 0x44, 0x33, 0x22, 0x11};

void respond() {
  char text[32] = "";
  radio.read(&text, 32);
  Serial.println(text);
}
*/

void setup() {
  Serial.begin(9600);
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Nie mozna znalezc MPU6050 - sprawdz polaczenie!");
    delay(500);
  }
  /*
  radio.begin();
  radio.setAutoAck(false);
  radio.setChannel(52);
  radio.setPayloadSize(32);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0, RXAddr);
  radio.startListening();
  attachInterrupt(IRQ_PIN, respond, FALLING);
  */
  
}

void loop() {
  Vector normAccel = mpu.readNormalizeAccel();
  Serial.print(" Xnorm = ");
  Serial.print(normAccel.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(normAccel.YAxis);
  Serial.print(" Znorm = ");
  Serial.println(normAccel.ZAxis);
  delay(10);
}
