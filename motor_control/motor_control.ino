// Display
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Motors
#include<Servo.h>
Servo servo_5;
Servo servo_4;

int pos_1 = 45;
int pos_2 = 45;
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

// Switch button
int button_pressed = 12;
int counter = 0;


void setup() 
{
  //Display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  
  Serial.begin(9600);
  //Motor 5
  servo_5.attach(10);
  servo_4.attach(9);
  // button
  
  pinMode(button_pressed,INPUT);

}

void loop() 
{

  potcontrol = analogRead(POTPIN);
  Serial.print("Potentiometer position: ");
  Serial.println(potcontrol);     // Print to Serial Monitor
  

  if (digitalRead(12) == HIGH){
    counter += 1;
  }
  Serial.print(" Counter: ");
  Serial.println(counter);

  display.clearDisplay();

  switch(counter % 3){
    // Motor 5
    case 0:
      pos_1 = float(potcontrol)/1024 * 90;
      Serial.print(" position_1: ");
      Serial.println(pos_1);     // Print to Serial Monitor
      servo_5.write(pos_1);
      // Print "motor 5" in normal size
      display.setTextSize(1);               // Header size
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(F("MOTOR 5 (TIP)"));
      // Print "90" in double size
      display.setTextSize(2);               // Double size
      display.setCursor(0, 16);             // Lower position
      display.print(F("LOC: "));
      display.println(pos_1);
      display.display();
      break;
    // Motor 4
    case 1:
      pos_2 = float(potcontrol)/1024*170;
      Serial.print(" position_2: ");
      Serial.println(pos_2);     // Print to Serial Monitor
      servo_4.write(pos_2);
      // Print "motor 5" in normal size
      display.setTextSize(1);               // Header size
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(F("MOTOR 4 (Elbow)"));
      // Print "90" in double size
      display.setTextSize(2);               // Double size
      display.setCursor(0, 16);             // Lower position
      display.print(F("LOC: "));
      display.println(pos_2);
      display.display();
      break;

    default:
      display.setTextSize(1);               // Header size
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(F("Choose a motor"));

      display.setTextSize(2);               // Double size
      display.setCursor(0, 16);             // Lower position
      display.print(F("CHOOSE "));
      display.display();
  }
}
