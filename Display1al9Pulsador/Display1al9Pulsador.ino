// Definición de pines para el display de 7 segmentos
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;

// Definición de pines para los pulsadores
const int buttonUp = 10;
const int buttonDown = 11;

// Variables para controlar el estado del número mostrado
int currentNumber = 0;
int lastButtonUpState = HIGH;
int lastButtonDownState = HIGH;

// Definición de los patrones para los números 0-9 en un display de 7 segmentos
int digits[10][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},      // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},   // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},   // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},    // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},   // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},  // 6
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},     // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // 8
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}   // 9
};

void setup() {
  // Configuración de los pines del display de 7 segmentos como salida
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  
  // Configuración de los pines de los pulsadores como entrada
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);

  // Mostrar el número inicial (0)
  showNumber(currentNumber);
}

void loop() {
  // Leer el estado de los pulsadores
  int buttonUpState = digitalRead(buttonUp);
  int buttonDownState = digitalRead(buttonDown);

  // Subir el número si se presiona el pulsador Up
  if (buttonUpState == LOW && lastButtonUpState == HIGH) {
    currentNumber++;
    if (currentNumber > 9) {
      currentNumber = 0;
    }
    showNumber(currentNumber);
    delay(200); // Retardo para evitar rebotes
  }

  // Bajar el número si se presiona el pulsador Down
  if (buttonDownState == LOW && lastButtonDownState == HIGH) {
    currentNumber--;
    if (currentNumber < 0) {
      currentNumber = 9;
    }
    showNumber(currentNumber);
    delay(200); // Retardo para evitar rebotes
  }

  // Guardar el estado de los pulsadores para la siguiente iteración
  lastButtonUpState = buttonUpState;
  lastButtonDownState = buttonDownState;
}

// Función para mostrar un número en el display de 7 segmentos
void showNumber(int number) {
  digitalWrite(a, digits[number][0]);
  digitalWrite(b, digits[number][1]);
  digitalWrite(c, digits[number][2]);
  digitalWrite(d, digits[number][3]);
  digitalWrite(e, digits[number][4]);
  digitalWrite(f, digits[number][5]);
  digitalWrite(g, digits[number][6]);
}

