/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-bluetooth
 */

// NOTE: change the Serial to other Serial/Software Serial if you connects Bluetooth module to other pins

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
    } else if (command == "0") {
      Serial.println("LED is turned ON"); // reports action to smartphone app
      // TODO: control your LED here
      digitalWrite(8, LOW);
    }
  }

  delay(500);
}
