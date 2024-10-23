int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int digitPins[7] = {a, b, c, d, e, f, g}; 
int controlPin = A0;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
  pinMode(controlPin, INPUT);
}

void loop() {
  int potValue = analogRead(controlPin);
  int num = map(potValue, 0, 1023, 0, 9);
  displayNumber(num);
  delay(100);
}

void displayNumber(int num) {
  byte segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };
  
  for (int i = 0; i < 7; i++) {
    digitalWrite(digitPins[i], segments[num][i]);
  }
}

