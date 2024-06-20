/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-bluetooth
 */

// NOTE: change the Serial to other Serial/Software Serial if you connects Bluetooth module to other pins
//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  

  Serial.println(F("Arduino here, command me!"));

  if (Serial.available()) { // if there is data comming
    String command = Serial.readStringUntil('\n'); // read string until meet newline character

    if (command == "1") {
      Serial.println("LED is turned OFF"); // reports action to smartphone app
      // TODO: control your LED here
      digitalWrite(8, HIGH);
      myStepper.setSpeed(10);
	    myStepper.step(stepsPerRevolution);
    } else if (command == "0") {
      Serial.println("LED is turned ON"); // reports action to smartphone app
      // TODO: control your LED here
      digitalWrite(8, LOW);
      myStepper.setSpeed(0);
	    myStepper.step(-stepsPerRevolution);
    }
  }

  delay(500);
}
