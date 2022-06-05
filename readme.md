# Before everything start, please power on your board, and check it if it works. #

## For developing, you can use ESP-idf or esp32-arduino. ##
```
We suggest you use platformIO it support both ESP-idf and arduino-esp32.
Install the platformIO with this guide: https://platformio.org/platformio-ide

or

Install arduino-esp32 for Arduino-IDE.
Install guide is here:
https://github.com/espressif/arduino-esp32#installation-instructions
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



**Note:**

code is adapted for new `platform_packages: framework-arduinoespressif32` and new verison toolchain

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

