#include<SPI.h>
const int CS_pin = 0;

void setup() {
  pinMode(CS_pin, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  SPISettings mySetting(1000000, MSBFIRST , SPI_MODE0);

}

void loop() {
  digitalWrite(CS_pin, LOW);
  int RxData = SPI.transfer(0x2f);
  Serial.print(RxData);

}
