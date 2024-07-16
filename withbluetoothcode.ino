#include <Servo.h>

Servo headServo; // Baş servo
Servo bodyServos[4]; // 4 vücut servo

char incomingByte; // Gelen seri veri için değişken

void setup() {
  Serial.begin(9600);
  
  // Servo pinlerini atanır
  headServo.attach(6); // Baş servo, pin 6
  bodyServos[0].attach(7); // Vücut servo 1, pin 7
  bodyServos[1].attach(8); // Vücut servo 2, pin 8
  bodyServos[2].attach(9); // Vücut servo 3, pin 9
  bodyServos[3].attach(10); // Vücut servo 4, pin 10

  // Tüm servolar başlangıç pozisyonuna getirilir
  resetSnake();
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    switch (incomingByte) {
      case 'f': // İleri hareket
        moveForward();
        break;
      case 'b': // Geri hareket
        moveBackward();
        break;
      case 'l': // Sol dönüş
        turnLeft();
        break;
      case 'r': // Sağ dönüş
        turnRight();
        break;
      case 's': // Durma
        stopMovement();
        break;
      case 'w': // Dalgalı hareket
        waveMotion();
        break;
      case 'z': // Başa dönme
        resetSnake();
        break;
    }
  }
}

void moveForward() {
  // İleri hareket için servo pozisyonları ayarlanır
  headServo.write(90);
  for (int i = 0; i < 4; i++) {
    bodyServos[i].write(120);
  }
}

void moveBackward() {
  // Geri hareket için servo pozisyonları ayarlanır
  headServo.write(90);
  for (int i = 0; i < 4; i++) {
    bodyServos[i].write(60);
  }
}

void turnLeft() {
  // Sol dönüş için servo pozisyonları ayarlanır
  headServo.write(120);
  for (int i = 0; i < 4; i++) {
    bodyServos[i].write(90);
  }
}

void turnRight() {
  // Sağ dönüş için servo pozisyonları ayarlanır
  headServo.write(60);
  for (int i = 0; i < 4; i++) {
    bodyServos[i].write(90);
  }
}

void stopMovement() {
  // Durma için servo pozisyonları ayarlanır
  headServo.write(90);
  for (int i = 0; i < 4; i++) {
    bodyServos[i].write(90);
  }
}

void resetSnake() {
  // Tüm servoların başlangıç pozisyonuna döndürülmesi
  headServo.write(90);
  for (int i = 0; i < 4; i++) {
    bodyServos[i].write(90);
  }
}

void waveMotion() {
  // Dalgalı hareket için servo pozisyonları ayarlanır
  headServo.write(90);
  bodyServos[0].write(120);
  bodyServos[1].write(60);
  bodyServos[2].write(120);
  bodyServos[3].write(60);
}