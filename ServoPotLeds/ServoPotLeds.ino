#include <Servo.h>

Servo myservo; // crea un objeto servo
int potPin = A0; // pin del potenciómetro
int ledPin0 = 2; // pin del LED para ángulo menor a 10
int ledPin90 = 3; // pin del LED para ángulo entre 85 y 95
int ledPin180 = 4; // pin del LED para ángulo mayor a 170
int val; // variable para almacenar el valor del potenciómetro

void setup() {
myservo.attach(9); // conecta el servomotor al pin 9
pinMode(ledPin0, OUTPUT);
pinMode(ledPin90, OUTPUT);
pinMode(ledPin180, OUTPUT);
}

void loop() {
val = analogRead(potPin); // lee el valor del potenciómetro (0-1023)
int angle = map(val, 0, 1023, 0, 180); // convierte el valor a un ángulo (0-180)
myservo.write(angle); // mueve el servomotor al ángulo correspondiente

// Apaga todos los LEDs
digitalWrite(ledPin0, LOW);
digitalWrite(ledPin90, LOW);
digitalWrite(ledPin180, LOW);

// Enciende el LED correspondiente al ángulo
if (angle < 10) {
digitalWrite(ledPin0, HIGH);
} else if (angle > 85 && angle < 95) {
digitalWrite(ledPin90, HIGH);
} else if (angle > 170) {
digitalWrite(ledPin180, HIGH);
}

delay(15); // espera para que el servomotor se mueva
}
