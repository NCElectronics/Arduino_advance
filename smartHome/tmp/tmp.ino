#include <Stepper.h>

int time = 0;
// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;
int buttonState = 0;
int blindsState = 0;
// 0 - off
// 1 - up
// 2 - off
// 3 - down

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() { Serial.begin(9600); }

void loop() {
  buttonState = digitalRead(2);
  Serial.println(buttonState);
  if (buttonState == HIGH) {
    // PRESSED:
    Serial.println("BUTTON OFF");
    signalProcessor(1.0);
    digitalWrite(12, LOW);
    //myStepper.setSpeed(20);
  } else {
    // NOT PRESSED
    Serial.println("BUTTON ON");
    signalProcessor(-0.1);
    //digitalWrite(12, HIGH);
    //myStepper.setSpeed(1);
  }
  Serial.println(blindsState);
  if(blindsState == 0)
  {
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  else if(blindsState == 1)
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  else if(blindsState == 2)
  {
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  else if(blindsState == 3)
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
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

float signal_counter = 0.0;
void signalProcessor(float signal)
{
  signal_counter += signal;
  if(signal_counter > 5.0) 
  {
    signal_counter = 0.0;
    updateBlindsState();
  }
  if(signal_counter < 0.0) 
  {
    signal_counter = 0.0;
  }
}

void updateBlindsState(){
  blindsState += 1;
  if(blindsState > 3)blindsState = 0;

}