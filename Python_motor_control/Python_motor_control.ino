// -----------------------------------
// Libraries and OLED Display Setup
// -----------------------------------
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// -----------------------------------
// Servo Motor Setup
// -----------------------------------
#include <Servo.h>
Servo servo_5;  // Motor on Pin 10
Servo servo_4;  // Motor on Pin 9
Servo servo_3;  // Motor on Pin 6
Servo servo_2;  // Motor on Pin 5
Servo servo_1;  // Motor on Pin 3



int pos_5 = 0;
int pos_4 = 0;
int pos_3 = 0;
int pos_2 = 0;
int pos_1 = 0;

bool motor5_synced = false;
bool motor4_synced = false;
bool motor3_synced = false;
bool motor2_synced = false;
bool motor1_synced = false;

int pos_5_a = 0;
int pos_4_a = 0;
int pos_3_a = 0;
int pos_2_a = 0;
int pos_1_a = 0;

int motorInt;



// Motor Angle Ranges (comment reference only)
// Motor 5 (Pin 10): Max 90°, Min 0°
// Motor 4 (Pin 9): Max 170°, Min 0°
// Motor 3 (Pin 6): Max 145°, Min 6°
// Motor 2 (Pin 5): Max 135°, Min 30° (Ideal: 80°)
// Motor 1 (Pin 3): Max 140°, Min 40°

// -----------------------------------
// Inputs: Potentiometer & Button
// -----------------------------------
int POTPIN = A1;
int potcontrol = 0;

int button_pin = 12;
int counter = 0;

// -----------------------------------
// Setup Function
// -----------------------------------
void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize Display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Attach Motors
  servo_5.attach(10);
  servo_5.write(0);

  servo_4.attach(9);
  servo_4.write(90);

  servo_3.attach(6);
  servo_3.write(30);

  servo_2.attach(5);
  servo_2.write(100);

  servo_1.attach(3);
  servo_1.write(0);

  // Configure Button Input
  pinMode(button_pin, INPUT);
}


void loop() {
  potcontrol = analogRead(POTPIN);
  if (Serial.available() > 0){
    String msg = Serial.readString();
    motorInt = msg.toInt();
  }

  if (digitalRead(12) == HIGH){
    counter += 1;
  }

  display.clearDisplay();

  switch(motorInt){
    // Motor 5
    case 0:
      // Motor 5
      motor4_synced = false;
      motor3_synced = false;
      motor2_synced = false;
      motor1_synced = false;

      pos_5_a = servo_5.read();
      pos_5 = float(potcontrol) / 1024 * 90;
      if ((abs(pos_5 - pos_5_a) > 10) && !(motor5_synced)){
        servo_5.write(pos_5_a);      
      }
      else{
        servo_5.write(pos_5);
        motor5_synced = true;
      }

      // Display info on OLED
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(F("MOTOR 5"));

      display.setTextSize(1);
      display.setCursor(0, 16);
      display.print(F("Control: "));
      display.println(pos_5);

      display.setTextSize(1);
      display.setCursor(0, 24);
      display.print(F("LOC: "));
      display.println(pos_5_a);
      display.display();
      break;

    case 1:
      // Motor 4
      motor5_synced = false;
      motor3_synced = false;
      motor2_synced = false;
      motor1_synced = false;

      pos_4_a = servo_4.read();
      pos_4 = float(potcontrol) / 1024 * 160;
      if ((abs(pos_4 - pos_4_a) > 10) && !(motor4_synced)){
        servo_4.write(pos_4_a);      
      }
      else{
        servo_4.write(pos_4);
        motor4_synced = true;
      }      

      // Display info on OLED
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(F("MOTOR 4"));

      display.setTextSize(1);
      display.setCursor(0, 16);
      display.print(F("Control: "));
      display.println(pos_4);

      display.setTextSize(1);
      display.setCursor(0, 24);
      display.print(F("LOC: "));
      display.println(pos_4_a);
      display.display();
      break;
      
    case 2:
      // Motor 3
      motor5_synced = false;
      motor4_synced = false;
      motor2_synced = false;
      motor1_synced = false;

      pos_3_a = servo_3.read();
      pos_3 = float(potcontrol) / 1024 * 130 + 10;
      if ((abs(pos_3 - pos_3_a) > 10) && !(motor3_synced)){
        servo_3.write(pos_3_a);      
      }
      else{
        servo_3.write(pos_3);
        motor3_synced = true;
      }      

      // Display info on OLED
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(F("MOTOR 3"));

      display.setTextSize(1);
      display.setCursor(0, 16);
      display.print(F("Control: "));
      display.println(pos_3);

      display.setTextSize(1);
      display.setCursor(0, 24);
      display.print(F("LOC: "));
      display.println(pos_3_a);
      display.display();
      break;

    case 3:
      // Motor 2
      motor5_synced = false;
      motor4_synced = false;
      motor3_synced = false;
      motor1_synced = false;

      pos_2_a = servo_2.read();
      pos_2 = float(potcontrol) / 1024 * 100 + 30;
      if ((abs(pos_2 - pos_2_a) > 10) && !(motor2_synced)){
        servo_2.write(pos_2_a);      
      }
      else{
        servo_2.write(pos_2);
        motor2_synced = true;
      }      

      // Display info on OLED
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(F("MOTOR 2"));

      display.setTextSize(1);
      display.setCursor(0, 16);
      display.print(F("Control: "));
      display.println(pos_2);

      display.setTextSize(1);
      display.setCursor(0, 24);
      display.print(F("LOC: "));
      display.println(pos_2_a);
      display.display();
      break;


    case 4:
      // Motor 1
      motor5_synced = false;
      motor4_synced = false;
      motor3_synced = false;
      motor2_synced = false;

      pos_1_a = servo_1.read();
      pos_1 = float(potcontrol) / 1024 * 160;
      if ((abs(pos_1 - pos_1_a) > 10) && !(motor1_synced)){
        servo_1.write(pos_1_a);      
      }
      else{
        servo_1.write(pos_1);
        motor1_synced = true;
      }      

      // Display info on OLED
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(F("MOTOR 1"));

      display.setTextSize(1);
      display.setCursor(0, 16);
      display.print(F("Control: "));
      display.println(pos_1);

      display.setTextSize(1);
      display.setCursor(0, 24);
      display.print(F("LOC: "));
      display.println(pos_1_a);
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