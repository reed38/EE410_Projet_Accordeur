#include <SoftwareSerial.h>
#include <TM1637Display.h>
#include "DHT.h"


#define TEMPERATURE_SENSOR 6
#define DHTTYPE DHT11
#define DHTPIN 4
#define BUTTONPIN 2

DHT temperatureSensor(TEMPERATURE_SENSOR, DHTTYPE);

//

SoftwareSerial bluetooth(9,8); // initialize bluetooth
TM1637Display display(4, 5);  // initialize Display



//



void setup(){
    bluetooth.begin(9600);
    pinMode(BUTTONPIN, INPUT_PULLUP);

    display.setBrightness(7); // You can adjust the brightness level (0-7)
    display.clear();    
    bluetooth.begin(9600); 
    temperatureSensor.begin();
     Serial.begin(9600);

    //
  
 
  Serial.println("ENTER AT Commands:");
}

bool isButtonPressed()
{
  int buttonState = digitalRead(BUTTONPIN); // Read the button state (HIGH or LOW)

  if (buttonState == LOW) 
  {
    return false;
    
  }
  else
  {
    return true;
    
  }
    delay(100); // Debounce delay to prevent multiple presses in rapid succession
  
}


void loop(){

    if(isButtonPressed())
    {
      int val= (int) temperatureSensor.readTemperature();
      display.showNumberDec(val);
      bluetooth.print("\nTemperature = ");
      bluetooth.print(val);
        delay(100);

      
    }
    delay(100);
 
}
