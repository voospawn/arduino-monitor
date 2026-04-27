#include <Wire.h>
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

int hour, volume;

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(115200);
  Serial.setTimeout(300);

  lcd.setCursor(0, 0);
  lcd.print("Ready!");

  while(true){
    if(Serial.available()){
      String cmd = Serial.readStringUntil('\n');

      cmd.trim();

      if(cmd == "PING"){
        Serial.println("MEGA2560");
        break;
      }
    }

    delay(10);
  }
}

void loop() { // lcd może 500 ms
  if(Serial.available() > 0){
    while(Serial.available() < 3) delay(1);
    volume = Serial.read();
    hour = Serial.read();
    char lenChanged = Serial.read();

    String lines[4];

    for(int i = 0; i < 4; i++){
      lines[i] = Serial.readStringUntil('\n');
      lines[i].trim();
    }
    
    if(lenChanged == 1){
      lcd.clear();
    }
    
    for(int i = 0; i < 4; i++){
      lcd.setCursor(0, i);
      lcd.print(lines[i]);
    }
  }
  
}
