// Definimos los pines para cada segmento del display
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;

// Matriz que define los segmentos para cada número del 0 al 9
const int numeros[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 0, 0, 1, 1}  // 9
};

void setup() {
  // Configuramos los pines como salidas
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    mostrarNumero(i);
    delay(1000); // Espera 1 segundo
  }
}

void mostrarNumero(int num) {
  digitalWrite(a, numeros[num][0]);
  digitalWrite(b, numeros[num][1]);
  digitalWrite(c, numeros[num][2]);
  digitalWrite(d, numeros[num][3]);
  digitalWrite(e, numeros[num][4]);
  digitalWrite(f, numeros[num][5]);
  digitalWrite(g, numeros[num][6]);
}

