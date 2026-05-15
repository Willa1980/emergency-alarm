const int BTN = 2;
const int BUZZER = 8;
const int LED = 13;

volatile bool alarm = false;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN), trigger, FALLING);
}

void loop() {
  if (alarm) digitalWrite(BUZZER, HIGH);
  digitalWrite(LED, !digitalRead(LED));
  delay(500);
}

void trigger() {
  alarm = true;
}
