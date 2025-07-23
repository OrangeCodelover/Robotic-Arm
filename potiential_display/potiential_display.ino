// Display
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Motors
#include<Servo.h>
Servo myservo;

int pos = 45;
// motor 5 (Pin 10)
// Max Angle 90 Min Angle 0
// motor 4 (Pin 9)
// Max Angle 90 Min Angle 0
// motor 3 (Pin 6)
// Max Angle 120 Min Angle 45
// motor 2 (Pin 5)
// Max Angle 140 Min Angle 40 (ideal 80)
// motor 1 (Pin 3)
// Max Angle 140 Min Angle 40 
int maxAngle = 90;
int minAngle = 0;

int testingSpeed = 50;

// Potentiometer
int POTPIN = A1;
int potcontrol = 0;


void setup() 
{
  //Display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  Serial.begin(9600);
  myservo.attach(10);
}

void loop() 
{

  // for (pos = maxAngle; pos >= minAngle; pos -=1 ){
  // myservo.write(pos);
  // delay(testingSpeed);
  // Serial.print("Servo position: ");
  // Serial.println(pos); 
  // }

  potcontrol = analogRead(POTPIN);
  Serial.print("Potentiometer position: ");
  Serial.println(potcontrol);     // Print to Serial Monitor
  pos = float( potcontrol)/1024*180;
  Serial.print(" position: ");
  Serial.println(pos);     // Print to Serial Monitor
  myservo.write(pos);

  display.clearDisplay();
  // Print "motor 5" in normal size
  display.setTextSize(1);               // Header size
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("MOTOR 5 (TIP)"));
  // Print "90" in double size
  display.setTextSize(2);               // Double size
  display.setCursor(0, 16);             // Lower position
  display.print(F("LOC: "));
  display.println(pos);
  display.display();
}
