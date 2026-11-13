// Simulation-only pin scan, no serial (compiled for Arduino Uno)
// Start marker: all pins HIGH, then each pin alone in order.
const int pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
const int count = sizeof(pins) / sizeof(pins[0]);

void setup() {
  for (int i = 0; i < count; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < count; i++) digitalWrite(pins[i], HIGH);
  delay(1500);
  for (int i = 0; i < count; i++) digitalWrite(pins[i], LOW);
  delay(500);
  for (int i = 0; i < count; i++) {
    digitalWrite(pins[i], HIGH);
    delay(400);
    digitalWrite(pins[i], LOW);
    delay(100);
  }
}
