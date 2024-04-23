void setup() {
  Serial.begin(19200, SERIAL_8N2);  // Inicia la comunicación serial a 19200 baudios y 8 bits, impar , y dos de stop
}

void loop() {
  if (Serial.available() > 0) { // Verifica si hay datos disponibles para leer
    String receivedString = ""; // Inicializa una cadena para almacenar los datos recibidos
    while (Serial.available()) { // Lee todos los datos disponibles
      char c = Serial.read(); // Lee el caracter recibido
      receivedString += c; // Concatena el caracter a la cadena recibida
    }
    Serial.println("Datos recibidos: " + receivedString); // Imprime los datos recibidos en el Serial Monitor
  }
}

