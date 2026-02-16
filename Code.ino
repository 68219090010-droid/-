const int trigPin = 2;
const int echoPin = 3;
const int relay1 = 6;
const int relay2 = 7;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance > 0 && distance < 20) {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
    delay(5000);

    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    delay(500);

    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    delay(5000);

    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
  }
  delay(100);
}
