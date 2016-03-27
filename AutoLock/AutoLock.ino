#include "Keyboard.h"

const int sensorPin1 = 12;
const int sensorPin2 = 13;

bool oldState = false;
bool newState = false;

void setup() {
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
}

void LockScreen() {
  // if connect pin 2 with GND, then no keyboard input
  if (digitalRead(2) == HIGH){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('l');
    Keyboard.releaseAll();
  }
}

void updateState() {
  oldState = newState;
}

bool isDetected() {
  int pin1 = digitalRead(sensorPin1);
  int pin2 = digitalRead(sensorPin2);
  if (pin1 == LOW && pin2 == LOW) {
    return false;
  } else {
    return true;
  }
}

void loop() {
  delay(200);
  newState = isDetected();
  if (newState==false && oldState==true) {
    LockScreen();
  }
  updateState();
}
