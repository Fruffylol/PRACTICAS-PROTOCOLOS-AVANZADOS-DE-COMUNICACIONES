#include <LiquidCrystal.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define dirección I2C del LCD
#define LCD_ADDRESS 0x27
// Direccion de ARDUINO
#define SLAVE1_ADDRESS 0x08
//Direccion del MSP
#define SLAVE2_ADDRESS 0x48

// Crear instancia para el LCD
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup() {
  Wire.begin(); // Inicializar I2C como maestro
  lcd.init();//inicializa la pantalla
  lcd.backlight();//Enciende la luz de fondo
  lcd.backlight(); // Encender retroiluminación
}

void loop() {
  // Enviar texto al LCD
  lcd.setCursor(0, 0);
  lcd.print("Hola LCD!");
  
  // Enviar carácter 'a' al esclavo 1
  Wire.beginTransmission(SLAVE2_ADDRESS);
  Wire.write('a');
  Wire.endTransmission();
  
  // Enviar carácter 'B' al esclavo 2
  Wire.beginTransmission(SLAVE1_ADDRESS);
  Wire.write('B');
  Wire.endTransmission();
  
  delay(1000); // Esperar 1 segundo antes de repetir
}