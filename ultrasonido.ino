// Definición de pines
const int triggerPin = 2; // Pin del trigger del sensor
const int echoPin = 3;    // Pin del echo del sensor
const int ledMenos10cm = 4;
const int led10a20cm = 5;
const int ledMas20cm = 6;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledMenos10cm, OUTPUT);
  pinMode(led10a20cm, OUTPUT);
  pinMode(ledMas20cm, OUTPUT);
}

void loop() {
  // Generar pulso en el pin del trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Calcular la distancia en centímetros
  long duracion = pulseIn(echoPin, HIGH);
  float distancia = duracion * 0.034 / 2;

  // Encender LEDs según la distancia medida
  if (distancia < 10) {
    digitalWrite(ledMenos10cm, HIGH);
    digitalWrite(led10a20cm, LOW);
    digitalWrite(ledMas20cm, LOW);
  } else if (distancia >= 10 && distancia <= 20) {
    digitalWrite(ledMenos10cm, LOW);
    digitalWrite(led10a20cm, HIGH);
    digitalWrite(ledMas20cm, LOW);
  } else {
    digitalWrite(ledMenos10cm, LOW);
    digitalWrite(led10a20cm, LOW);
    digitalWrite(ledMas20cm, HIGH);
  }
}
