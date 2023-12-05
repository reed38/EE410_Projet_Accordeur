#include <Wire.h>
#include "rgb_lcd.h"
#include <arduinoFFT.h>
rgb_lcd lcd;
#define SAMPLES 64
#define SAMPLING_FREQUENCY 1000

int GUITAR_IN = A0;
double frequency = 0;

arduinoFFT FFT = arduinoFFT();

unsigned int sampling_period_us;
unsigned long microseconds;

double vReal[SAMPLES];
double vImag[SAMPLES];
String tune = "good";

void setup() {
  sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQUENCY));
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Projet accordeur");
  lcd.setCursor(0, 1);
  lcd.print("Demarrage");
  delay(2000);
  pinMode(GUITAR_IN, INPUT);
  Serial.begin(9600);
}

double FindFrequency() {
  for (int i = 0; i < SAMPLES; i++) {
    microseconds = micros();
    vReal[i] = analogRead(GUITAR_IN);
    vImag[i] = 0;
    while (micros() < (microseconds + sampling_period_us))
      ;
  }

  /*FFT*/
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
  double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);

  peak = peak * 0.990;
  return peak;
}

void loop() {
  frequency = FindFrequency();

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(frequency);
  lcd.setCursor(5, 1);
  lcd.print("Hz");

  // -------------------- Différentes fréquences des notes a détecter -------------------------

  // E2 a peu près 82.5
  if (frequency >= 75 && frequency <= 90) {
    if (frequency < 81.5) {
      lcd.setCursor(0, 0);
      lcd.print("  <<<  E2       ");
      Serial.println("note trop basse pour E2 (Mi grave)");
      Serial.println(frequency);
    }
    if (frequency > 83.5) {
      lcd.setCursor(0, 0);
      lcd.print("       E2  >>>  ");
      Serial.println("note trop haute pour E2 (Mi grave)");
      Serial.println(frequency);
    }
    if (frequency >= 81.5 && frequency <= 83.5) {
      //lcd.clear();
      lcd.setCursor(7, 0);
      lcd.print("E2");
      lcd.setCursor(11, 1);
      lcd.print(tune);
      Serial.println("E2 (Mi grave) accordé");
      Serial.println(frequency);
    }
  }
  // A2 110.54
  else if (frequency <= 120.00 && frequency >= 100.00) {
    if (frequency < 108.00) {
      lcd.setCursor(0, 0);
      lcd.print("  <<<  A2       ");
      Serial.println("note trop basse pour A2 (La)");
      Serial.println(frequency);
    }
    if (frequency > 112.00) {
      lcd.setCursor(0, 0);
      lcd.print("       A2  >>>  ");
      Serial.println("note trop haute pour A2 (La)");
      Serial.println(frequency);
    }
    if (frequency >= 108.00 && frequency <= 112.00) {
      //lcd.clear();
      lcd.setCursor(7, 0);
      lcd.print("A2");
      lcd.setCursor(11, 1);
      lcd.print(tune);
      Serial.println("A2 (La) accordé");
      Serial.println(frequency);
    }
  }
  // D3 147
  else if (frequency >= 130.00 && frequency <= 150.00) {
    if (frequency < 145) {
      lcd.setCursor(0, 0);
      lcd.print("  <<<  D3       ");
      Serial.println("note trop basse pour D3(Ré)");
      Serial.println(frequency);
    }
    if (frequency > 148) {
      lcd.setCursor(0, 0);
      lcd.print("       D3  >>>  ");
      Serial.println("note trop haute pour D3(Ré)");
      Serial.println(frequency);
    }
    if (frequency >= 145 && frequency <= 148) {
      //lcd.clear();
      lcd.setCursor(7, 0);
      lcd.print("D3");
      lcd.setCursor(11, 1);
      lcd.print(tune);
      Serial.println("D3(Ré) accordé");
      Serial.println(frequency);
    }
  }
  // G3 199
  else if (frequency >= 180.00 && frequency <= 210.00) {
    if (frequency < 193.00) {
      lcd.setCursor(0, 0);
      lcd.print("  <<<  D3       ");
      Serial.println("note trop basse pour G3(Sol)");
      Serial.println(frequency);
    }
    if (frequency > 199.00) {
      lcd.setCursor(0, 0);
      lcd.print("       G3  >>>  ");
      Serial.println("note trop haute pour G3(Sol)");
      Serial.println(frequency);
    }
    if (frequency >= 193.00 && frequency <= 199.00) {
      //lcd.clear();
      lcd.setCursor(7, 0);
      lcd.print("G3");
      lcd.setCursor(9, 1);
      lcd.print(tune);
      Serial.println("D3(Sol) accordé");
      Serial.println(frequency);
    }
  }
  // B3 250
  else if (frequency >= 230.00 && frequency <= 260.00) {
    if (frequency < 246) {
      lcd.setCursor(0, 0);
      lcd.print("  <<<  B3       ");
      Serial.println("note trop basse pour B3(Si)");
      Serial.println(frequency);
    }
    if (frequency > 251) {
      lcd.setCursor(0, 0);
      lcd.print("       B3  >>>  ");
      Serial.println("note trop haute pour B3(Si)");
    }
    if (frequency >= 245 && frequency <= 251) {
      //lcd.clear();
      lcd.setCursor(7, 0);
      lcd.print("B3");
      lcd.setCursor(10, 1);
      lcd.print(tune);
      Serial.println("B3(Si) accordé");
      Serial.println(frequency);
    }
  }
  // E4 330
  else if (frequency >= 310.00 && frequency <= 355.00) {
    if (frequency < 328) {
      lcd.setCursor(0, 0);
      lcd.print("  <<<  E4       ");
      Serial.println("note trop basse pour E4(Mi aigu)");
      Serial.println(frequency);
    }
    if (frequency > 334) {
      lcd.setCursor(0, 0);
      lcd.print("       E4  >>>  ");
      Serial.println("note trop haute pour E4(Mi aigu)");
      Serial.println(frequency);
    }
    if (frequency >= 328 && frequency <= 334) {
      //lcd.clear();
      lcd.setCursor(7, 0);
      lcd.print("E4");
      lcd.setCursor(10, 1);
      lcd.print(tune);
      Serial.println("E4(Mi aigu) accordé");
      Serial.println(frequency);
    }
  }
  delay(1000);
}
