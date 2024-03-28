#include <Stepper.h>

int time = 0;
// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;
int buttonState = 0;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() { Serial.begin(9600); }

void loop() {
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    // PRESSED:
    Serial.println("BUTTON ON");
    digitalWrite(12, HIGH);
    //myStepper.setSpeed(20);
  } else {
    // NOT PRESSED
    Serial.println("BUTTON OFF");
    digitalWrite(12, LOW);
    //myStepper.setSpeed(1);
  }
  //myStepper.step(stepsPerRevolution);
  delay(100);
  // myStepper.setSpeed(5);
	// myStepper.step(stepsPerRevolution);
  // Serial.print("the value is ");
  // Serial.println(time++);
  // Serial.println(" seconds");
  // delay(100);

}