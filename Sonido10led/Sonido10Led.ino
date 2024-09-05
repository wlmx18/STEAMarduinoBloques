// Definición de pines
const int sensorPin = A0; // Pin analógico para el sensor de sonido
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // Pines digitales para los LEDs

void setup() {
  // Configuración de los pines de los LEDs como salidas
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600); // Inicialización de la comunicación serial
}

void loop() {
  // Lectura del valor analógico del sensor de sonido
  int soundValue = analogRead(sensorPin);

  // Mapeo del valor del sensor (0-1023) al rango de LEDs (0-7)
  int ledCount = map(soundValue, 0, 1023, 0, 10);

  // Encendemos los LEDs según la intensidad del sonido
  for (int i = 0; i < 10; i++) {
    if (i < ledCount) {
      digitalWrite(ledPins[i], HIGH); // Encender LED
    } else {
      digitalWrite(ledPins[i], LOW); // Apagar LED
    }
  }

  // Enviamos el valor del sensor por la comunicación serial (para depuración)
  Serial.print("Valor del sensor: ");
  Serial.println(soundValue);

  delay(100); // Pequeña pausa para evitar lecturas rápidas
}
