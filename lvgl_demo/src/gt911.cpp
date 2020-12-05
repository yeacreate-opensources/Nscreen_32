/*
 *  GT911 TP driver for arduino/esp8266/esp32
 * auther: simon@yeacreate.com
 * I2C TP:
 * SCL:D22[GPIO22]
 * SDA:D21[GPIO21]
 * INT:D5
 * RST:D23
 */
#include <Arduino.h>
#include "config.h"
#include "Wire.h"
#include "gt911.h"

tp_service::tp_service() {}
tp_service::~tp_service() {}

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR tp_service::readi2c(uint16_t addr, uint8_t *inputbuff, size_t size)
{
  uint8_t pos = 0;

  Wire.beginTransmission(GOODIX_I2C_ADDR);
  Wire.write(highByte(addr));
  Wire.write(lowByte(addr));
#ifdef _TP_DEBUG_
  Serial.printf("[INFO][TP] I2C writen 0x%02x to 0x%02x \n", highByte(addr), GOODIX_I2C_ADDR);
  Serial.printf("[INFO][TP] I2C writen 0x%02x to 0x%02x \n", lowByte(addr), GOODIX_I2C_ADDR);

  uint8_t res;
  res = Wire.endTransmission();
  if (res != 0)
  {
    Serial.printf("[ERR][TP] I2C tranmission error\n");
  }
#else
  Wire.endTransmission();
#endif

  Wire.requestFrom(GOODIX_I2C_ADDR, size);

  while (Wire.available()) // slave may send less than requested
  {
    inputbuff[pos] = Wire.read(); // receive a byte as character
    pos++;

#ifdef _TP_DEBUG_
    Serial.printf("[INFO][TP][DATA] Reg:0x%04x Data[%d] is 0x%02x \n", addr, pos - 1, inputbuff[pos - 1]);
#endif
  }

  Wire.endTransmission(false); //send nack end
} //end readi2c()

void ICACHE_FLASH_ATTR tp_service::setup()
{
#ifdef _TP_DEBUG_
  Serial.println("[INFO][TP] GT911 TP driver for arduino/esp8266/esp32 !");
#endif

#ifdef _TP_DEBUG_
  Serial.print("[INFO][TP] I2C speed is ");
  Serial.println(I2C_SPEED);
#endif

  Wire.begin(TP_SDA, TP_SCL, I2C_SPEED);
#ifdef _TP_DEBUG_
  Serial.print("[INFO][TP] I2C wire begin \n");
#endif
  delay(200);

  TP_INT_SETUP_OUT;
  TP_RST_SETUP;
  TP_RST_OFF;
  TP_INT_OFF;
  /* T2: > 10ms */
  delay(50);

  //    TP_INT_ON;
  // /* T3: > 100us */
  //   delay(1);

  TP_RST_ON;
  /* T4: > 5ms */
  // delay(10);
  // TP_INT_OFF;
  /* end select I2C slave addr */

  /* T5: 50ms */
  delay(60);
  TP_INT_SETUP_IN; // INT pin has no pullups so simple set to floating input

#ifdef _TP_DEBUG_
  Serial.println("[INFO][TP] TP initial finished !");
  Serial.print("[INFO][TP] Check ACK on addr request on 0x");
  Serial.print(GOODIX_I2C_ADDR, HEX);
  Wire.beginTransmission(GOODIX_I2C_ADDR);
  int error = Wire.endTransmission();
  if (error == 0)
  {
    Serial.println(": SUCCESS");
  }
  else
  {
    Serial.print(": ERROR #");
    Serial.println(error);
  }
  // read_firmware_info();
#endif
  delay(100);
  update_config();
#ifdef _TP_DEBUG_
  read_firmware_info();
  Serial.printf("[INFO][GT911][UPTIME] %ld \n", millis());
#endif

  get_xy.touch = false;
  attachInterrupt(TP_INT, irq_handle, RISING);
} //end setup()

void ICACHE_FLASH_ATTR tp_service::update_config()
{
  //get chksum
  for (uint8_t c = 0; c < (GOODIX_I2C_CONFIG_SIZE - 3); c++)
  {
    gt911FW[GOODIX_I2C_CONFIG_SIZE - 2] += gt911FW[c];
  }
  gt911FW[GOODIX_I2C_CONFIG_SIZE - 2] = (~gt911FW[GOODIX_I2C_CONFIG_SIZE - 2]) + 1;
#ifdef _TP_DEBUG_
  Serial.printf("[INFO][TP][UPDATE_CONFIG] Chksum is 0x%02x \n", gt911FW[GOODIX_I2C_CONFIG_SIZE - 2]);
#endif
  //end get chksum

  //send configs
  for (uint8_t w = 0; w < GOODIX_I2C_CONFIG_SIZE; w++)
  {
    Wire.beginTransmission(GOODIX_I2C_ADDR);
    Wire.write(highByte(GOODIX_I2C_CONFIG_START_ADDR + w));
    Wire.write(lowByte(GOODIX_I2C_CONFIG_START_ADDR + w));
    Wire.write(gt911FW[w]);
#ifdef _TP_DEBUG_
    Serial.printf("[INFO][TP][UPDATE_CONFIG] Witren configs[%d] 0x%02x \n", w, gt911FW[w]);
#endif
    Wire.endTransmission(); //sent end
  }

#ifdef _TP_DEBUG_
  uint8_t config_buff1[I2C_BUFFER_LENGTH];
  uint8_t config_buff2[GOODIX_I2C_CONFIG_SIZE - I2C_BUFFER_LENGTH];

  readi2c(GOODIX_I2C_CONFIG_START_ADDR, config_buff1, I2C_BUFFER_LENGTH);                                              //the 1st 128 configs
  readi2c(GOODIX_I2C_CONFIG_START_ADDR + I2C_BUFFER_LENGTH, config_buff2, GOODIX_I2C_CONFIG_SIZE - I2C_BUFFER_LENGTH); //the resets configs

  for (int i = 0; i < I2C_BUFFER_LENGTH; i++)
  {
    Serial.printf("[INFO][TP][DATA] The new config is 0x%02x \n", config_buff1[i]);
  }

  for (int j = 0; j < (GOODIX_I2C_CONFIG_SIZE - I2C_BUFFER_LENGTH); j++)
  {
    Serial.printf("[INFO][TP][DATA] The new config is 0x%02x \n", config_buff2[j]);
  }

  cinfo configs;
  configs.config_version = config_buff1[0];
  configs.x_max_output = (config_buff1[2] << 8) + config_buff1[1];
  configs.y_max_output = (config_buff1[4] << 8) + config_buff1[3];
  configs.touch_number = config_buff1[5];

  Serial.printf("[INFO][TP][CONFIGS] The Config Version is: %d \n", configs.config_version);
  Serial.printf("[INFO][TP][CONFIGS] The X Output Max is: %d \n", configs.x_max_output);
  Serial.printf("[INFO][TP][CONFIGS] The Y Output Max is: %d \n", configs.y_max_output);
  Serial.printf("[INFO][TP][CONFIGS] Total Touch Number is: %d \n", configs.touch_number);
#endif

} //end update_config()

#ifdef _TP_DEBUG_
void ICACHE_FLASH_ATTR tp_service::read_firmware_info()
{
  finfo fwinfos;
  uint8_t buff[FW_INFO_SIZE];
  readi2c(GOODIX_I2C_FW_ADDR, buff, FW_INFO_SIZE);
  fwinfos.product_id[0] = buff[0];
  fwinfos.product_id[1] = buff[1];
  fwinfos.product_id[2] = buff[2];
  fwinfos.product_id[3] = buff[3];

  fwinfos.firmware_version = buff[4] + (buff[5] << 8);
  fwinfos.x_resolution = buff[6] + (buff[7] << 8);
  fwinfos.y_resolution = buff[8] + (buff[9] << 8);
  fwinfos.vendor_id = buff[10];

  Serial.print("[INFO][TP][FW] The Product ID is:");
  Serial.println(fwinfos.product_id);
  Serial.printf("[INFO][TP][FW] The Firmware version is: %d \n", fwinfos.firmware_version);
  Serial.printf("[INFO][TP][FW] The X coordinate resolution is: %d \n", fwinfos.x_resolution);
  Serial.printf("[INFO][TP][FW] The Y coordinate resolution is: %d \n", fwinfos.y_resolution);
  Serial.printf("[INFO][TP][FW] The Vendor ID is: %d \n", fwinfos.vendor_id);
} //end read_firmware_info()
#endif

void ICACHE_FLASH_ATTR tp_service::read_coordinate()
{

  uint8_t buff[GOODIX_I2C_READXY_SIZE];
  readi2c(GOODIX_I2C_READXY_ADDR, buff, GOODIX_I2C_READXY_SIZE);

  get_xy.x = buff[2] + (buff[3] << 8);
  get_xy.y = buff[4] + (buff[5] << 8);
  get_xy.touch = buff[0] >> 6;

#ifdef _TP_DEBUG_
  Serial.printf("[INFO][TP][TOUCH] X is %d \n", get_xy.x);
  Serial.printf("[INFO][TP][TOUCH] Y is %d \n", get_xy.y);
  Serial.printf("[INFO][TP][TOUCH] Touch status is %d \n", get_xy.touch);
#endif

  if (get_xy.touch == 1)
  {
    Wire.beginTransmission(GOODIX_I2C_ADDR);
    Wire.write(highByte(GOODIX_I2C_READXY_ADDR));
    Wire.write(lowByte(GOODIX_I2C_READXY_ADDR));
    Wire.write(0x00);

#ifdef _TP_DEBUG_
    Serial.printf("[INFO][TP][RBS] Reseted buffer status \n");
#endif
    Wire.endTransmission(); //sent end
  }

} //end read_coordinate()

bool ICACHE_FLASH_ATTR tp_service::get_touch(uint16_t pressthou)
{

  if (act_time > millis() && millis() < 5000)
    act_time = millis(); //prevent millis reset
  if (millis() > act_time)
  {
    act_time = millis() + pressthou;
    if (IRQ == true)
    {
      IRQ = false;
      read_coordinate();
      if (get_xy.touch == false)
        return false;
      return true;
    }
  }
  return false;
} //end get_touch()

/* =========================end icache functions======================== */
/* =========================== iram functions=========================== */
void IRAM_ATTR irq_handle()
{
  IRQ = true;
} //end irq_handle()

/* ===========================end iram functions=========================== */

// void loop()
// {

//   if (get_touch(50))
//   {
//     Serial.printf("[INFO][TP] X is %d \n", get_xy.x);
//     Serial.printf("[INFO][TP] Y is %d \n", get_xy.y);
//     Serial.printf("[INFO][TP] Touch status is %d \n", get_xy.touch);
//     Serial.printf("[INFO][UPTIME] %ld \n", millis());
//   }
// }
