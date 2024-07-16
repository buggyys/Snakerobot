#include <Servo.h>
Servo myServos[6]; // 6 servos

int TotalNumberofServos = 6; // number of servos
int waveSpeed = 5; // Speed of the wave movement
int waveSize = 30; // Size of the wave

void setup() {
  Serial.begin(9600);
  
  // Servos are attached to the respective pins
  myServos[0].attach(6);  // Tail - Servo 1 attached to digital pin 6
  myServos[1].attach(7);  // Servo 2 attached to digital pin 7
  myServos[2].attach(8);  // Servo 3 attached to digital pin 8
  myServos[3].attach(9);  // Servo 4 attached to digital pin 9
  myServos[4].attach(10); // Servo 5 attached to digital pin 10
  myServos[5].attach(11); // Head - Servo 6 attached to digital pin 11

  // Set servos to the initial position (90 degrees)
  for (int i = 0; i < 6; i++) {
    myServos[i].write(90);
    delay(500); // Delay a bit to allow each servo to reset
  }

  // Delay to allow servos to reach the initial position
  delay(1000);
}

void makeWave() {
  // Move servos in a wavy motion
  for (int angle = 0; angle <= 360; angle += waveSpeed) {
    for (int i = 0; i < TotalNumberofServos; i++) {
      int servoPos = 90 + waveSize * sin(radians(angle + i * (360 / TotalNumberofServos)));
      myServos[i].write(servoPos);
    }
    delay(10); // Adjust delay for smoother or faster movement
  }
}

void resetSnake() {
  // Reset all servos to their initial position
  for (int i = 0; i < TotalNumberofServos; i++) {
    myServos[i].write(90);
  }
}

void loop() {
  makeWave(); // Make a wave motion
  resetSnake(); // Reset the snake to its initial position
}