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
#define TOUCH_CALIBRATION 0


/*
 This test case is copied and modified from 
 "lvgl\examples\arduino\LVGL_Arduino\LVGL_Arduino.ino"
*/
#include <Arduino.h>

#include <lvgl.h>
#include <TFT_eSPI.h>
/*If you want to use the LVGL examples,
  make sure to install the lv_examples Arduino library
  and uncomment the following line.
#include <lv_examples.h>
*/

#include "config.h"
#include "gt911.h"

#include "esp_freertos_hooks.h"

#include "demos/lv_demos.h"
#include "demos/widgets/lv_demo_widgets.h"
#include "demos/benchmark/lv_demo_benchmark.h"
#include "demos/stress/lv_demo_stress.h"
#include "demos/music/lv_demo_music.h"
#include "demos/keypad_encoder/lv_demo_keypad_encoder.h"

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

#if TOUCHPAD
tp_service tp;  /*touchpad instance*/
#endif

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

#if TOUCHPAD
/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
    bool touched = tp.get_touch(50);
    if (tp.get_xy.touch == 0)
    {
        return;
    }

    if (tp.get_xy.x > screenHeight || tp.get_xy.y > screenWidth)
    {
#ifdef _DEBUG_
        Serial.printf("[INFO][DISPLAY][TOUCH][ERR]Y or y outside of expected parameters.. X=%d, Y=%d\n", tp.get_xy.x, tp.get_xy.y);
#endif
    }
    else
    {

        data->state = (tp.get_xy.touch == true) ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
        // data->state = LV_INDEV_STATE_PR;

        /*Save the state and save the pressed coordinate*/
        //if(data->state == LV_INDEV_STATE_PR) touchpad_get_xy(&last_x, &last_y);
        if (data->state == LV_INDEV_STATE_PR)
        {
            //data->point.x = tp.get_xy.x;
            //data->point.y = tp.get_xy.y;
            /* ROTATION==1 */
            data->point.x = tp.get_xy.y;
            data->point.y = 319-tp.get_xy.x;
#ifdef _DEBUG_
            Serial.printf("[INFO][TP] X is %d \n", tp.get_xy.x);
            Serial.printf("[INFO][TP] Y is %d \n", tp.get_xy.y);
            Serial.printf("[INFO][TP] Touch status is %d \n", tp.get_xy.touch);
            Serial.printf("[INFO][UPTIME] %ld \n", millis());
            Serial.printf("[INFO][MEM] FREE memory %d \n", ESP.getFreeHeap());
#endif
        }
    }

    return; /*Return `false` because we are not buffering and no more data to read*/
}
#endif


static void lv_tick_task()
{   
   lv_tick_inc(portTICK_PERIOD_MS);
}

void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */

    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println( LVGL_Arduino );
    Serial.println( "I am LVGL_Arduino" );

#if TOUCHPAD //touch initialization
    tp.setup();
#endif

    lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

    tft.begin();          /* TFT init */
    /* Landscape orientation, flipped 
       0, 1, 2, 3 ==> 0°、90°、180°、270°   
    */
    tft.setRotation( ROTATION ); 

#if TOUCH_CALIBRATION
    /*Set the touchscreen calibration data,
     the actual data for your display can be acquired using
     the Generic -> Touch_calibrate example from the TFT_eSPI library*/
    uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
    tft.setTouch( calData );
#endif

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

#if TOUCHPAD //touch_setup
    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv ); 
#endif

    /* This is copied from  https://gitee.com/rillhu/esp32-lvgl-dev.git DEMOS
       And it fixed the drawing stop issue.
       To trigger lvgl task run, you need call lv_tick_inc from below hook.
    */
    esp_register_freertos_tick_hook(lv_tick_task); 


#if 0
    /* Create simple label */
    lv_obj_t *label = lv_label_create( lv_scr_act() );
    lv_label_set_text( label, LVGL_Arduino.c_str() );
    lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );
#else
    /* Try an example from the lv_examples Arduino library
       make sure to include it as written above.
    lv_example_btn_1();
   */

    // uncomment one of these demos
     lv_demo_widgets();            // OK
    // lv_demo_benchmark();          // OK
    // lv_demo_keypad_encoder();     // works, but I haven't an encoder
    // lv_demo_music();              // OK
    // lv_demo_stress();             // seems to be OK
#endif
    Serial.println( "Setup done" );
}



void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay( 5 );
}

