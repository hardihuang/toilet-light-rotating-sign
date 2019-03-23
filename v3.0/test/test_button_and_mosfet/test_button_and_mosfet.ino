void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
}

void loop() {
  int sensorVal = digitalRead(2);
  if (sensorVal == HIGH) {
    digitalWrite(4, LOW);
  } else {
    digitalWrite(4, HIGH);
  }

}
