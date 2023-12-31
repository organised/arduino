// This code is for displaying a bitmap on the 
// ESP32 S3 Development Board with 0.42 Inch OLED LCD using the U8G2 library
/*
ESP32-S3FH4R2 Dual Core 240MHz Tensilica processor
Type-C USB
4MB Flash2M PSRAM
13x IO
1x1.0-4P connector(GND,3V3,SDA(GPIO2),SCL(GPIO1))
1x RGB(GPIO39)
1xLED(3.3V Power Supply)
1xReset button(great for restarting your program or entering the bootloader)
1xBoot button(GPIO0,entering the ROM bootloader or for user input)
Compatible with for MicroPython, for and ESP-IDF
3.3V Regulator with 500mA output
Ceramic Antenna
Size: 23.5 x 18 mm
Weight: 2.6g
DOCUMENTS
https://github.com/01Space/ESP32-S3-0.42OLED
*/

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define SDA_PIN 41
#define SCL_PIN 40

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// XBMP file definition
#define head_closeup_width 72
#define head_closeup_height 40
static unsigned char head_closeup_bits[] = {
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0xc0, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x07, 0xfc, 0x3f, 0xc0, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x07, 0xfc, 0x3f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xfc,
   0x3f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xfc, 0x3f, 0xc0, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x07, 0xfc, 0x3f, 0xc0, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x07, 0xfc, 0x3f, 0x00, 0xc0, 0x07, 0x00, 0xe0, 0x03, 0x00, 0xfc,
   0x3f, 0x00, 0xc0, 0x07, 0x00, 0xe0, 0x03, 0x00, 0xfc, 0x3f, 0x00, 0xc0,
   0x07, 0x00, 0xe0, 0x03, 0x00, 0xfc, 0x3f, 0x00, 0xc0, 0x07, 0x00, 0xe0,
   0x03, 0x00, 0xfc, 0x3f, 0x00, 0xc0, 0x07, 0x00, 0xe0, 0x03, 0x00, 0xfc,
   0x3f, 0x00, 0xc0, 0x07, 0x00, 0xe0, 0x03, 0x00, 0xfc, 0x3f, 0x00, 0xc0,
   0x07, 0x00, 0xe0, 0x03, 0x00, 0xfc, 0x3f, 0x00, 0xc0, 0x07, 0x00, 0xe0,
   0x03, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };


void setup(void) {
  Wire.begin(SDA_PIN, SCL_PIN);
  u8g2.begin();
}

void loop(void) {
  u8g2.clearBuffer(); // clear the internal memory
  u8g2.setDrawColor(0);
  u8g2.drawXBMP(0, 0, head_closeup_width, head_closeup_height, head_closeup_bits); // draw XBMP
  u8g2.sendBuffer(); // transfer internal memory to the display
  delay(1000); // delay in between updates
}