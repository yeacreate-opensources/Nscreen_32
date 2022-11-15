/*
480x320 4.0 inch ST7796 parallel display project with GT911 touch screen
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
--------------------------
I2C TP:7
SCL:D22[GPIO22]
SDA:D21[GPIO21]
INT:D5
RST:D23
--------------------------
===============================================
*/

#include <Arduino.h>
#include "soc/timer_group_struct.h"  //for wdt
#include "soc/timer_group_reg.h"     //for wdt
#include "config.h"
#include "io_service.h"
#include "gt911.h"
#include "display_service.h"


TaskHandle_t cpu0 = NULL;
TaskHandle_t cpu1 = NULL;
io_service io;           //load IO control service
display_service display; //load display service
tp_service tp;


inline void feedTheDog(){
  // feed dog 0
  TIMERG0.wdt_wprotect=TIMG_WDT_WKEY_VALUE; // write enable
  TIMERG0.wdt_feed=1;                       // feed dog
  TIMERG0.wdt_wprotect=0;                   // write protect
  // feed dog 1
  TIMERG1.wdt_wprotect=TIMG_WDT_WKEY_VALUE; // write enable
  TIMERG1.wdt_feed=1;                       // feed dog
  TIMERG1.wdt_wprotect=0;                   // write protect
}

inline void loop_cpu0(void){
   display.loop();
}

inline void loop_cpu1(void){
}

void setup_cpu0(void *pvParameters){
    display.setup();
    for(;;) {
          loop_cpu0();
      }

}

void setup_cpu1(void *pvParameters){
    io.setup();
    tp.setup();
    for(;;) {
          loop_cpu1();
      }
}
void setup()
{

    xTaskCreatePinnedToCore(
                    setup_cpu0,   /* Task function. */
                    "cpu0",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &cpu0,      /* Task handle to keep track of created task */
                    0);         /* pin task to core 0 */ 

    xTaskCreatePinnedToCore(
                    setup_cpu1,   /* Task function. */
                    "cpu1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &cpu1,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
}

void loop(void)
{
  feedTheDog();
}