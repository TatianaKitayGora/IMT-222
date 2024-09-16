// Pines del display de 7 segmentos
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;

// Pin del botón

int botonPin = 9;

// Variables de estado
int contador = 0;
bool contar = true;

// Matriz para los dígitos del display de 7 segmentos
int digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,0,0,1,1}   // 9
};

void setup() {
  // Configurar los pines como salida para el display
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  // Configurar el pin del botón como entrada
  pinMode(botonPin, INPUT_PULLUP); // Configuración con resistencia de pull-up interna

  // Configurar la interrupción
  attachInterrupt(digitalPinToInterrupt(botonPin), interrumpir, FALLING);
}

void loop() {
  if (contar) {
    showNumber(contador);
    delay(1000); // Retraso de 1 segundo
    contador++;
    if (contador > 9) {
      contador = 0; // Reiniciar el contador después de 9
    }
  }
}

void interrumpir() {
  contar = !contar; // Negar el conteo
}

void showNumber(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(a + i, digits[num][i]);
  }
}
