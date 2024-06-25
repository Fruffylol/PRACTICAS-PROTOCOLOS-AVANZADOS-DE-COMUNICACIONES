#include <Wire.h>

void setup() {
  Wire.begin(0x08); // Unir al bus I2C con la dirección 0x08
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    char c = Wire.read(); // Leer el carácter recibido
    Serial.print("Esclavo 1 recibido: ");
    Serial.println(c);
  }
}
