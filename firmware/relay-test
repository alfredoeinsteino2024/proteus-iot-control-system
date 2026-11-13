#define RELAY_ON  LOW
#define RELAY_OFF HIGH

const int relayPins[4] = {2, 3, 6, 19};

void setup() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(relayPins[i], RELAY_OFF);
    pinMode(relayPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(relayPins[i], RELAY_ON);
    delay(1000);
    digitalWrite(relayPins[i], RELAY_OFF);
    delay(500);
  }
}
