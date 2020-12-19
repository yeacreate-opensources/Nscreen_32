/*
 * GT911 TP driver for arduino/esp8266/esp32
 * auther: simon@yeacreate.com
 * I2C TP:
 * SCL:D22[GPIO22]
 * SDA:D21[GPIO21]
 * INT:D5
 * RST:D23
 */
#ifndef GT911_H
#define GT911_H

#define TP_VERSION "0.0.0.1" //driver version

#define TP_RST_SETUP (pinMode(TP_RST, OUTPUT))
#define TP_RST_ON (digitalWrite(TP_RST, HIGH))
#define TP_RST_OFF (digitalWrite(TP_RST, LOW))
#define TP_INT_SETUP_OUT (pinMode(TP_INT, OUTPUT))
#define TP_INT_ON (digitalWrite(TP_INT, HIGH))
#define TP_INT_OFF (digitalWrite(TP_INT, LOW))
#define TP_INT_SETUP_IN (pinMode(TP_INT, INPUT))
// 8bit Device read address:0xBB
// 8bit Device write address:0x29
// so, 0xBB/0x29 >> 1 is 0x5D/0x14(7bit)
#define GOODIX_I2C_ADDR 0x5D

#define GOODIX_I2C_CONFIG_START_ADDR 0X8047
#define GOODIX_I2C_CONFIG_SIZE 186

#define GOODIX_I2C_READXY_ADDR 0x814E
#define GOODIX_I2C_READXY_SIZE 6

#ifdef _TP_DEBUG_
// firmware information
#define GOODIX_I2C_FW_ADDR 0X8140
#define FW_INFO_SIZE 11
#endif

class tp_service
{
private:
    uint8_t gt911FW[GOODIX_I2C_CONFIG_SIZE] = {
        0x41, //0x8047 config_version
        0x40, //0x8048 X output Max(Low byte)
        0x01, //0x8049 X output Max(High byte)
        0xe0, //0x804A Y output Max(Low byte)
        0x01, //0x804B Y output Max(High byte)
        0x01, //0x804C Touch Number
        0xf5, //0x804D Module_switch1(Bit[0-1]:INT trigger,[2]:Software noise reduction,[3]:x/y exchange,[4-5]:reversal,[6]:x2x reversal,[7]:y2y reversal)
        0x00,
        0x01, //0x804F Shake_count
        0x08, 0x1e, 0x0f, 0x50, 0x32, 0x03, 0x05, 0x00, 0x00,0x00, 
        0x00,
        0x00, //space FF is max per 4 bit. [4:7] uper space, [0:3]:down space
        0x00, //space FF is max per 4 bit. [4:7] left space, [0:3]:right space
        0x00, 0x18, 0x1a, 0x1e, 0x14, 0x87, 0x28, 0x0a, 0x3c, 0x3e, 
        0xeb, 0x04, 0x00, 0x00, 0x00, 0xb0, 0x03, 0x2d, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x03, 0x64, 0x32, 0x00, 0x00, 0x00, 0x19, 
        0x64, 0x94, 0xc5, 0x02, 0x02, 0x00, 0x00, 0x04, 0xdd, 0x1c, 
        0x00, 0xae, 0x26, 0x00, 0x8f, 0x32, 0x00, 0x79, 0x42, 0x00, 
        0x68, 0x57, 0x00, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e, 0x10, 0x12, 0x14, 
        0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x26, 0x24, 0x22, 0x21, 0x20, 0x1f, 0x1e, 0x1d, 0x0c, 0x0a, 
        0x08, 0x06, 0x04, 0x02, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00,
        0x00, //chuksum, should be 0 for calculating by function
        0x01  //data_fresh
    };
    /* ==================================structs================================= */
#ifdef _TP_DEBUG_
    typedef struct config_info
    {
        uint8_t config_version : 8;
        uint16_t x_max_output : 16;
        uint16_t y_max_output : 16;
        uint8_t touch_number : 3;
    } cinfo;

    typedef struct firmware_info
    {
        // 0x8140
        char product_id[4];        //0x8140-0x8143
        uint16_t firmware_version; //0x8144-0x8145
        uint16_t x_resolution;     //0x8146-0x8147
        uint16_t y_resolution;     //0x8148-0x8149
        uint8_t vendor_id;         //0x814A
    } finfo;
#endif

    typedef struct touch_info
    {
        uint16_t x : 16;   //0x8150-0x8151
        uint16_t y : 16;   //0x8152-0x8153
        boolean touch : 1; //0x814E(bit:7)
    } tpxy;
    /* =============================end structs================================== */
    /* ==============================variables=================================== */
    uint64_t act_time = 0;
    /* ============================end variables================================= */
    /* =============================icache functions============================= */
    void ICACHE_FLASH_ATTR readi2c(uint16_t addr, uint8_t *inputbuff, size_t size);
    void ICACHE_FLASH_ATTR read_coordinate();
    void ICACHE_FLASH_ATTR update_config();
#ifdef _TP_DEBUG_
    void ICACHE_FLASH_ATTR read_firmware_info();
#endif
    /* ============================end icache functions========================== */

    /* =============================iram functions=============================== */
    /* ============================end iram functions============================ */

public:
    tp_service();
    ~tp_service();

    /* =============================icache functions============================= */
    void ICACHE_FLASH_ATTR setup();
    bool ICACHE_FLASH_ATTR get_touch(uint16_t pressthou);
    tpxy get_xy;
    /* ============================end icache functions========================== */

    /* =============================iram functions=============================== */
    /* ============================end iram functions============================ */
};
/* =============================public icache functions============================= */
/* ============================end public icache functions========================== */

/* =============================public iram functions=============================== */
static bool IRQ = false;
static void IRAM_ATTR irq_handle();
/* ============================end public iram functions============================ */
#endif
