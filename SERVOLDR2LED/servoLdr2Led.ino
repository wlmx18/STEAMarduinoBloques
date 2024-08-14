#include <Servo.h>

Servo myservo;  // crea el objeto servo
int ldrPin = A0;  // pin del LDR
int servoPin = 9;  // pin del servo
int ledPin2 = 2;  // pin del LED 2
int ledPin3 = 3;  // pin del LED 3
int ldrValue = 0;  // valor del LDR

void setup() {
  myservo.attach(servoPin);  // conecta el servo al pin 9
  pinMode(ledPin2, OUTPUT);  // configura el pin 2 como salida
  pinMode(ledPin3, OUTPUT);  // configura el pin 3 como salida
  Serial.begin(9600);  // inicia la comunicación serial
}

void loop() {
  ldrValue = analogRead(ldrPin);  // lee el valor del LDR
  Serial.println(ldrValue);  // imprime el valor del LDR en el monitor serial

  if (ldrValue > 500) {  // si hay luz
    myservo.write(90);  // mueve el servo a 90 grados
    digitalWrite(ledPin2, HIGH);  // enciende el LED en el pin 2
    digitalWrite(ledPin3, LOW);  // apaga el LED en el pin 3
  } else {  // si hay oscuridad
    myservo.write(0);  // mueve el servo a 0 grados
    digitalWrite(ledPin2, LOW);  // apaga el LED en el pin 2
    digitalWrite(ledPin3, HIGH);  // enciende el LED en el pin 3
  }

  delay(1000);  // espera 1 segundo antes de la siguiente lectura
}

