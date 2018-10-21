// include the library code:
#include <LiquidCrystal.h>

// Constantes para la inicialización del LCD
#define RS 12
#define ENABLE 11
#define d4 5
#define d5 4
#define d6 3
#define d7 2
#define FILAS 2
#define COLUMNAS 16
#define BASE 10

// Puerto analógico 0
#define A0 0

// https://www.arduino.cc/en/Reference/LiquidCrystalConstructor
LiquidCrystal lcd(RS, ENABLE, d4, d5, d6, d7);

int val=0;
int iluminacion = 0;

void setup() {
  // Establece numero de filas y columnas
  lcd.begin(COLUMNAS, FILAS);
}

void loop() {
  // Cambio posición cursor
  lcd.setCursor(0, 0);
  lcd.print("En este momento");
  lcd.setCursor(0, 1);
  val = analogRead(A0);
  iluminacion =map(val,54, 974, 0, 100);

  String textoLCD = String("hay " + String(iluminacion, BASE) + "% de luz     ");
  lcd.print(textoLCD);

}
