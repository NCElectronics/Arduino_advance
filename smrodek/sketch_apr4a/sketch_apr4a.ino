// the setup function runs once when you press reset or power the board
#define POTENCJOMETR_PIN 0
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  Serial.begin(57600);
  while (!Serial);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(2, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(2, LOW);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait for a second
  digitalWrite(3, HIGH);
  delay(1000);                      // wait for a second
  digitalWrite(3, LOW);
  delay(500);                      // wait for a second
  digitalWrite(4, HIGH);
  delay(1000);                      // wait for a second
  digitalWrite(4, LOW);
  delay(500);
  digitalWrite(5, HIGH);
  delay(1000);                      // wait for a second
  digitalWrite(5, LOW);
  delay(500);

  int value = analogRead(POTENCJOMETR_PIN);
  Serial.println(value, DEC);

  delay(20);
}
