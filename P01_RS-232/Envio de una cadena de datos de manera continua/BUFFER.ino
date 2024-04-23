#define BUFFER_SIZE 12 // Tamaño del buffer

unsigned long TiempoH = 0;

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 19200 baudios
}

void loop() {
  static char receivedBuffer[BUFFER_SIZE]; // Buffer para almacenar los datos recibidos
  static int currentIndex = 0; // Índice actual en el buffer
  
  if (Serial.available() > 0) { // Verifica si hay datos disponibles para leer

    char receivedChar = Serial.read(); // Lee el caracter recibido

    if (receivedChar == 10 || currentIndex >= BUFFER_SIZE - 1) { // Si se recibe un salto de línea o el buffer está lleno

      receivedBuffer[currentIndex] = '\0'; // Termina la cadena con un carácter nulo

      if (currentIndex >= BUFFER_SIZE - 1) { // Si el buffer está lleno
        Serial.print("Buffer lleno!: ");
        Serial.println(receivedBuffer); // Imprime los datos recibidos en el Serial Monitor
        currentIndex = 0; // Reinicia el índice

      } else { // Si se recibe un salto de línea
        Serial.print("Datos recibidos: ");
        Serial.println(receivedBuffer); // Imprime los datos recibidos en el Serial Monitor
        currentIndex = 0; // Reinicia el índice
      }
    } else{
      receivedBuffer[currentIndex++] = receivedChar; // Almacena el caracter en el buffer y aumenta el índice
    }
    TiempoH = millis();
  }
  int x = millis() - TiempoH; 
  if (x > 5000){
    currentIndex = 0;
  }
}

