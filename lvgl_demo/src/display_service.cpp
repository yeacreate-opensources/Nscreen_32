#include <Arduino.h>
#include "config.h"
#include "display_service.h"
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "gt911.h"
#include "example/lv_demo_widgets.h"


extern TFT_eSPI tft = TFT_eSPI(); //load tft service
extern tp_service tp;             //load tp service

display_service::display_service() {}
display_service::~display_service() {}


static lv_disp_buf_t disp_buf;
static lv_color_t buf1[DISP_BUF_SIZE];

#if (BUF_NUM== 2)
static lv_color_t buf2[DISP_BUF_SIZE];
#endif

/* =============================icache functions========================= */
#ifdef TOUCHPAD
void ICACHE_FLASH_ATTR display_service::touch_setup()
{
  /*Initialize the touch pad*/
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);
#ifdef _DEBUG_
  Serial.print(F("[INFO] Touch setup finished! \n"));
#endif
}
#endif


void ICACHE_FLASH_ATTR display_service::lv_setup()
{
  lv_init();
  tft.begin();               /* TFT init */
  tft.setRotation(ROTATION); /* Landscape orientation */
#if (BUF_NUM == 1)
  lv_disp_buf_init(&disp_buf, buf1, NULL, DISP_BUF_SIZE);
#elif (BUF_NUM == 2)
  lv_disp_buf_init(&disp_buf, buf1, buf2, DISP_BUF_SIZE);
#endif

  /*Initialize the display*/
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = LV_HOR_RES_MAX;
  disp_drv.ver_res = LV_VER_RES_MAX;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.buffer = &disp_buf;
  lv_disp_drv_register(&disp_drv);

  lv_obj_t *scr = lv_cont_create(NULL, NULL);
  lv_disp_load_scr(scr);

  lv_demo_widgets();

#ifdef _DEBUG_
  Serial.print(F("[INFO] Display GUI setup finished! \n"));
#endif
}

void ICACHE_FLASH_ATTR display_service::setup()
{
  tft.init(); //setup tft servcie
  tft.fillScreen(TFT_WHITE);
  lv_setup();

#ifdef TOUCHPAD
  touch_setup();
#endif
 
  lv_main();

} // end display service setup

/* =========================end icache functions======================== */

/* =========================== iram functions=========================== */
#ifdef TOUCHPAD
bool IRAM_ATTR display_service::my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{

     bool touched = tp.get_touch(50);
    if (tp.get_xy.touch == 0)
    {
        return false;
    }

    if (tp.get_xy.x > LV_HOR_RES_MAX || tp.get_xy.y > LV_VER_RES_MAX)
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
            data->point.x = tp.get_xy.x;
            data->point.y = tp.get_xy.y;
#ifdef _DEBUG_
            Serial.printf("[INFO][TP] X is %d \n", tp.get_xy.x);
            Serial.printf("[INFO][TP] Y is %d \n", tp.get_xy.y);
            Serial.printf("[INFO][TP] Touch status is %d \n", tp.get_xy.touch);
            Serial.printf("[INFO][UPTIME] %ld \n", millis());
            Serial.printf("[INFO][MEM] FREE memory %d \n", ESP.getFreeHeap());
#endif
        }
    }

    return false; /*Return `false` because we are not buffering and no more data to read*/
}
#endif


void IRAM_ATTR display_service::lv_main()
{

#ifdef _DEBUG_
  Serial.print(F("[INFO] LV GUI started.\n"));
#endif
    // header_create();
    // body_create();

}


void IRAM_ATTR display_service::loop()
{
  lv_task_handler(); /* let the GUI do its work */
} //end loop

/* Display flushing */
void IRAM_ATTR display_service::my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.startWrite();
    tft.pushColors(&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

/* ===========================end iram functions=========================== */
