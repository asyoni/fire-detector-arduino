// www.asyoni.com

// Kode Fire Detector

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
int buzzer = 8;
int flamePin  = 2; 

void setup(){ 
  pinMode(buzzer,OUTPUT);   
  pinMode(flamePin, INPUT); 
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop(){
 
  lcd.print("   Fire Alarm   ");
  int flameSensor = digitalRead(flamePin);
    if (flameSensor==LOW){   
    lcd.setCursor(0,1);
    lcd.print(" Flame Detected ");
    digitalWrite(buzzer, HIGH); 
  }
  else 
  {
    lcd.setCursor(0,1);
    lcd.print(".....Normal.....");
    digitalWrite(buzzer, LOW);  
  }

}
