#define D6 13  // SCK
#define D7 12  // MISO
#define D8 11  // MOSI

#include "nRF24L01.h"
#include "RF24.h"
#include "SPI.h"
byte  data [ 1 ] ;
boolean  var ;


RF24 radio(3, 2); // CE,CS
const byte address[6]="00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "YOU ARE IN SECTOR 1 AND ABOUT TO LEAVE IT";
  radio.write(&text, sizeof(text));
  delay(1000);
}
