#include <Wire.h>
#include <SPI.h>
#include "RF24.h"
#include "nRF24L01.h"
#include "MPU6050.h"
#include "printf.h"

#define CE_PIN 0 //Fizyczny pin 2
#define CSN_PIN 1 //Fizyczny pin 3
#define IRQ_PIN 2 //Fizyczny pin 4

RF24 radio(CE_PIN, CSN_PIN);
MPU6050 mpu;

const byte adress[6] = {0xAA, 0x44, 0x33, 0x22, 0x11};

void setup() {
  printf_begin();
  Serial.begin(115200);
  radio.begin();
  if (radio.isChipConnected()) {
    Serial.println("Connected");
  }
  else {
    Serial.println("Not connected");
  }
  radio.setAutoAck(false);
  radio.openReadingPipe(0, adress);
  radio.setChannel(52);
  radio.setPayloadSize(32);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0, adress);
  radio.startListening();
  radio.printDetails();
  
}

void loop() {
  
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
  
  
}
