#include <Arduino.h>
#include "io_service.h"
#include "config.h"

io_service::io_service() {}
io_service::~io_service() {}

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR io_service::setup()
{
#ifdef _DEBUG_
  Serial.begin(115200);
  Serial.print(F("\n"));
  Serial.print(F("[INFO] Yea Nscreen System V "));
  Serial.println(VERSION);
  Serial.print(F("[INFO] Project name: "));
  Serial.println((String)DEV_TYPE);
  Serial.print(F("========================================\n"));
#endif

} // end io setup

// void ICACHE_FLASH_ATTR io_service::loop()
// {

// } //end loop

/* =========================end icache functions======================== */
/* =========================== iram functions=========================== */

/* ===========================end iram functions=========================== */