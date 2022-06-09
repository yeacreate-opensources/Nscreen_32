/*
VERSION "0.0.0.2" :

480x320 4.0 inch ST7796 parallel display project
connectons：
===============================================
TFT---esp32
VCC:5v
GND:GND
CS   33  // Chip select control pin
DC/RS  15  // Data Command control pin - must use a pin in the range 0-31 also named RS
RST  32  // Reset pin
WR    4  // Write strobe control pin - must use a pin in the range 0-31
RD    2
TFT_D0   12  // Must use pins in the range 0-31 for the data bus
TFT_D1   13  // so a single register write sets/clears all bits
TFT_D2   26
TFT_D3   25
TFT_D4   19
TFT_D5   18
TFT_D6   27
TFT_D7   14
===============================================

*/

#include <Arduino.h>
#include "config.h"
#include "display_service.h"


display_service display; //load display service


void setup()
{
  Serial.begin(115200);
  Serial.print(F("\n"));
  Serial.print(F("[INFO] YeaCreate Nscreen-32 tft_espi_graphicstest V "));
  Serial.println(VERSION);
  Serial.print(F("[INFO] Device name: "));
  Serial.println((String)DEV_TYPE);
  Serial.print(F("========================================\n"));
  display.setup();
}

void loop(void)
{
  display.loop();
// delay(5);
}
