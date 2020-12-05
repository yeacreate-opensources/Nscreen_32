#ifndef DISPLAY_SERVICE_H
#define DISPLAY_SERVICE_H

#include "TFT_eSPI.h"

class display_service
{
private:
  unsigned long total = 0;
  unsigned long tn = 0;
  unsigned long testFillScreen();
  unsigned long testText();
  unsigned long testLines(uint16_t color);
  unsigned long testFastLines(uint16_t color1, uint16_t color2);
  unsigned long testRects(uint16_t color);
  unsigned long testFilledRects(uint16_t color1, uint16_t color2);
  unsigned long testFilledCircles(uint8_t radius, uint16_t color);
  unsigned long testCircles(uint8_t radius, uint16_t color);
  unsigned long testTriangles();
  unsigned long testFilledTriangles();
  unsigned long testRoundRects();
  unsigned long testFilledRoundRects();
  

public:
  display_service();
  ~display_service();

  /* =============================iram functions=============================== */
  void setup();
  void loop();
  /* ============================end iram functions============================ */
};
#endif
