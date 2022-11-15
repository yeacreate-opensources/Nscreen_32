#define VERSION "0.0.0.4" //version number
#define _DEBUG_           //debug switch
#define DEV_TYPE "Nscreen_32"
#define LVGL_TICK_PERIOD 10 //lvgl tick period
#define ROTATION 0          //set ui rotation
#define TOUCHPAD //whether the UI support touch pad
// #define _TP_DEBUG_ //TP debug




//----------------------------tp configaction
#ifdef TOUCHPAD

#define I2C_SPEED 400000
#define TP_SCL 22
#define TP_SDA 21
#define TP_INT 5
#define TP_RST 23

#endif
//----------------------------end tp configaction


//------------------------start display select
#define BUF_SIZE 80
#define DISP_BUF_SIZE (LV_HOR_RES_MAX * BUF_SIZE)
#define BUF_NUM 1
//------------------------end display select