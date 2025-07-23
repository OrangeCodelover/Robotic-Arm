#include<Servo.h>

Servo myservo;


int pos = 0;
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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(10);
    for (pos = minAngle; pos <= maxAngle; pos +=1 ){
    myservo.write(pos);
    delay(testingSpeed);
  }
  for (pos = maxAngle; pos >= minAngle; pos -=1 ){
    myservo.write(pos);
    delay(testingSpeed);
  }
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

  pos = myservo.read();    // Read last written position
  Serial.print("Servo position: ");
  Serial.println(pos);     // Print to Serial Monitor

}
