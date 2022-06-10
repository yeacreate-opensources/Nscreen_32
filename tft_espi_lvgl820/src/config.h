#define VERSION "0.0.0.4" //version number
#define _DEBUG_           //debug switch
#define DEV_TYPE "Nscreen_32"

#define ROTATION 1       //set ui rotation

#define TOUCHPAD  1//whether the UI support touch pad
// #define _TP_DEBUG_ //TP debug




//----------------------------tp configaction
#if TOUCHPAD 

#define I2C_SPEED 400000
#define TP_SCL 22
#define TP_SDA 21
#define TP_INT 5
#define TP_RST 23

#endif
//----------------------------end tp configaction


