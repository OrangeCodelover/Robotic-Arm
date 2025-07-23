#include<Servo.h>

Servo myservo_1;
Servo myservo_2;
Servo myservo_3;
Servo myservo_4;
Servo myservo_5;

int pos_1 = 0;
int pos_2 = 0;
int pos_3 = 0;
int pos_4 = 0;
int pos_5 = 0;
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

int maxAngle_1 = 10;
int minAngle_1 = 0;

int maxAngle_2 = 140;
int minAngle_2 = 40;

int maxAngle_3 = 120;
int minAngle_3 = 45;

int maxAngle_4 = 120;
int minAngle_4 = 60;

int maxAngle_5 = 60;
int minAngle_5 = 0;


int testingSpeed = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Booting...");
// Motor 1
  myservo_1.attach(3);
  for (pos_1 = minAngle_1; pos_1 <= maxAngle_1; pos_1 +=1 ){
    myservo_1.write(pos_1);
    delay(testingSpeed);
  }
  for (pos_1 = maxAngle_1; pos_1 >= minAngle_1; pos_1 -=1 ){
    myservo_1.write(pos_1);
    delay(testingSpeed);
  }
// Motor 2
  myservo_2.attach(5);
  for (pos_2 = minAngle_2; pos_2 <= maxAngle_2; pos_2 +=1 ){
    myservo_2.write(pos_2);
    delay(testingSpeed);
  }
  for (pos_2 = maxAngle_2; pos_2 >= minAngle_2; pos_2 -=1 ){
    myservo_2.write(pos_2);
    delay(testingSpeed);
  }
// Motor 3
  myservo_3.attach(6);
  for (pos_3 = minAngle_3; pos_3 <= maxAngle_2; pos_3 +=1 ){
    myservo_3.write(pos_3);
    delay(testingSpeed);
  }
  for (pos_3 = maxAngle_3; pos_3 >= minAngle_3; pos_3 -=1 ){
    myservo_3.write(pos_3);
    delay(testingSpeed);
  }
// Motor 4
  myservo_4.attach(9);
  for (pos_4 = minAngle_4; pos_4 <= maxAngle_4; pos_4 +=1 ){
    myservo_4.write(pos_4);
    delay(testingSpeed);
  }
  for (pos_4 = maxAngle_4; pos_4 >= minAngle_4; pos_4 -=1 ){
    myservo_4.write(pos_4);
    delay(testingSpeed);
  }
// Motor 5
  myservo_5.attach(10);
  for (pos_5 = minAngle_5; pos_5 <= maxAngle_5; pos_5 +=1 ){
    myservo_5.write(pos_5);
    delay(testingSpeed);
  }
  for (pos_5 = maxAngle_5; pos_5 >= minAngle_5; pos_5 -=1 ){
    myservo_5.write(pos_5);
    delay(testingSpeed);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  pos_1 = myservo_1.read();    // Read last written position
  myservo_2.write(80);
  pos_2 = myservo_2.read();
  pos_3 = myservo_3.read();
  myservo_4.write(90);
  pos_4 = myservo_4.read();
  pos_5 = myservo_5.read();


  Serial.print("Servo 1 position: ");
  Serial.println(pos_1);
  Serial.print("Servo 2 position: ");
  Serial.println(pos_2);
  Serial.print("Servo 3 position: ");
  Serial.println(pos_3);
  Serial.print("Servo 4 position: ");
  Serial.println(pos_4);
  Serial.print("Servo 5 position: ");
  Serial.println(pos_5);

}
