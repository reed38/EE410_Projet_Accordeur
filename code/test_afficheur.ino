#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() {
  lcd.begin(16, 2);
}


void loop() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("test aficheur");             // ou lcd.print(nom de la variable à afficher);
  delay(100);
}
