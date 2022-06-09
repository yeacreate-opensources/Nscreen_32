# Before everything start, please power on your board, and check it if it works. #

## For developing, you can use ESP-idf or esp32-arduino. ##
```
We suggest you use platformIO it support both ESP-idf and arduino-esp32.
Install the platformIO with this guide: https://platformio.org/platformio-ide
```


## There are 3 demos here: ##
1.tft_espi_graphicstest
```
Used for test the screen only.
```

2. lvgl_benchmark
```
Used for run the benchmark programme. And touch screen driver included.
```

3. lvgl_demo
```
Used for the LVGL demo.And touch screen driver included.
```



###  Note 1: Adapting 3 old demos

Above 3 demos are adapted for new `platform_packages: framework-arduinoespressif32` and new version toolchain.

Current toolchain is as below:

```
PACKAGES: 
 - framework-arduinoespressif32 @ 3.20003.0 (2.0.3) 
 - tool-esptoolpy @ 1.30300.0 (3.3.0) 
 - tool-openocd-esp32 @ 2.1100.20220411 (11.0) 
 - toolchain-xtensa-esp32 @ 8.4.0+2021r2-patch3
```

platformio.ini

```
platform_packages =
  ; use a special branch
  ; framework-arduinoespressif32 @ https://github.com/espressif/arduino-esp32.git#idf-release/v4.0
  framework-arduinoespressif32
```

Current libraries version:

```
Dependency Graph
|-- lv_arduino @ 3.0.1
|-- TFT_eSPI @ 2.4.61
|   |-- SPIFFS @ 2.0.0
|   |   |-- FS @ 2.0.0
|   |-- FS @ 2.0.0
|   |-- LittleFS @ 2.0.0
|   |   |-- FS @ 2.0.0
|   |-- SPI @ 2.0.0
|-- Wire @ 2.0.0
```



### Note 2: update lvgl to version 8.2.0 and adapt the original demos

Current toolchain is as below:

Adapt latest lvgl version and adapt original demos

```
Verbose mode can be enabled via `-v, --verbose` option
CONFIGURATION: https://docs.platformio.org/page/boards/espressif32/nscreen-32.html
PLATFORM: Espressif 32 (4.4.0) > YeaCreate NSCREEN-32
HARDWARE: ESP32 240MHz, 320KB RAM, 16MB Flash
DEBUG: Current (cmsis-dap) External (cmsis-dap, esp-prog, iot-bus-jtag, jlink, minimodule, olimex-arm-usb-ocd, olimex-arm-usb-ocd-h, olimex-arm-usb-tiny-h, olimex-jtag-tiny, tumpa)
PACKAGES: 
 - framework-arduinoespressif32 @ 3.20003.0 (2.0.3) 
 - tool-esptoolpy @ 1.30300.0 (3.3.0) 
 - tool-openocd-esp32 @ 2.1100.20220411 (11.0) 
 - toolchain-xtensa-esp32 @ 8.4.0+2021r2-patch3
```

Current libraries version:

```
Dependency Graph
|-- lvgl @ 8.2.0
|-- TFT_eSPI @ 2.4.61
|   |-- SPIFFS @ 2.0.0
|   |   |-- FS @ 2.0.0
|   |-- FS @ 2.0.0
|   |-- LittleFS @ 2.0.0
|   |   |-- FS @ 2.0.0
|   |-- SPI @ 2.0.0
Building in release mode
```



### TODO

- [ ] Add GT911 support in new demos `tft_espi_lvgl820`

