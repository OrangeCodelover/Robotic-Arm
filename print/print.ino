#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() 
{
  // Print "motor 5" in normal size
  display.setTextSize(1);               // Header size
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("MOTOR 5 (TIP)"));
  // Print "90" in double size
  display.setTextSize(2);               // Double size
  display.setCursor(0, 16);             // Lower position
  display.println(F("LOC: 90"));
  display.display();
}
