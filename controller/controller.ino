#include <Wire.h>
#include <SPI.h>
#include "RF24.h"
#include "nRF24L01.h"
#include "MPU6050_6Axis_MotionApps20.h"

//Definicja pinów
#define CE_PIN 0 //Fizyczny pin 2, CE Radia
#define CSN_PIN 1 //Fizyczny pin 3, CSN Radia
#define IRQ_PIN 2 //Fizyczny pin 4, Przerwanie radia
#define B1_PIN 3 //Fizyczny pin 5, Przycisk
#define D1_PIN 4 //Fizyczny pin 6, Dioda LED

//Struktura, która będzie wysyłana do STM
struct ResponseOneContr {
  int16_t accX;
  int16_t accY;
  int16_t startContr;
  int16_t checksum;
};

int32_t accXSum, accYSum;
uint16_t counter; 

//Zmienne globalne dla radia
ResponseOneContr response;
RF24 radio(CE_PIN, CSN_PIN);
const byte RXAddr1[6] = {0xAA, 0x44, 0x33, 0x22, 0x11}; //Adres kontrolera, pierwszy bajt 0xAA dla kontrolera 1, 0xBB dla kontrolera 2
char readBuf[32];

//Zmienne globalne dla MPU
MPU6050 mpu;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];
Quaternion q;
VectorInt16 aa;
VectorInt16 aaReal;
VectorInt16 aaWorld;
VectorFloat gravity;

//Inicjalizacja radia
void radioInit() {
  radio.begin();
  radio.setAutoAck(true);
  radio.setChannel(52);
  radio.setPayloadSize(32);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.enableAckPayload(); //Odpowiedź kontrolera (z danymi) będzie zwracana jako ACK
  radio.openReadingPipe(1, RXAddr1);
  radio.startListening();
}

//Inicjalizacja MPU
void mpuInit() {
  mpu.initialize();
  if (mpu.testConnection() != true) Serial.println("Blad polaczenia z MPU"); 
  if (mpu.dmpInitialize() == 0) {
    Serial.println("Kalibracja");
    mpu.CalibrateAccel(6);
    mpu.CalibrateGyro(6);
    mpu.setDMPEnabled(true);
    packetSize = mpu.dmpGetFIFOPacketSize();
    Serial.println("Kalibracja zakonczona");
  } 
}

//Odczytanie wartości z MPU
void mpuRead() {
  mpu.resetFIFO();
  fifoCount = mpu.getFIFOCount();
  while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount(); //Czytaj dopóki nie przeczytasz wszystkiego
  mpu.getFIFOBytes(fifoBuffer, packetSize);
}

//Funkcja do obsługi przerwania radia
void respond() {
  if (radio.available()) {
    radio.read(readBuf, 32); //Oczyszczanie bufora poprzez read() (chodź nic w praktyce nie czytamy, trzeba czyścić bufor)
    accXSum = 0;
    accYSum = 0;
    counter = 0;
  }
}

void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(B1_PIN, INPUT_PULLUP);
  pinMode(D1_PIN, OUTPUT);
  digitalWrite(D1_PIN, LOW);
  mpuInit();
  radioInit();
  attachInterrupt(IRQ_PIN, respond, FALLING);
  radio.read(readBuf, 32); //Oczyszczanie bufora poprzez read()
  accXSum = 0;
  accYSum = 0;
  counter = 0;
  digitalWrite(D1_PIN, HIGH); //Dioda się zapali po kalibracji MPU - można podnieść kontroler i zacząć grać
}

void loop() {
  //Wczytaj dane z MPU
  mpuRead();

  //Wylicz przyspieszenie liniowe
  mpu.dmpGetQuaternion(&q, fifoBuffer);
  mpu.dmpGetAccel(&aa, fifoBuffer);
  mpu.dmpGetGravity(&gravity, &q);
  mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
  mpu.dmpGetLinearAccelInWorld(&aaWorld, &aaReal, &q);

  accXSum += (int16_t)aaWorld.y;
  accYSum += (int16_t)aaWorld.z;
  counter++;

  //Wypełnij bufer do wysłania do STM
  response.accX = accXSum / counter;
  response.accY = accYSum / counter;
  if (digitalRead(B1_PIN) == LOW) response.startContr = 1; //Sprawdź, czy naciskany jest przycisk
  else response.startContr = 0;
  response.checksum = response.accX + response.accY + response.startContr;

  //Wyślij bufer jako odpowiedź (ACK) na przychodzący pakiet  
  radio.writeAckPayload(1, (char*)&response, 32);
}
