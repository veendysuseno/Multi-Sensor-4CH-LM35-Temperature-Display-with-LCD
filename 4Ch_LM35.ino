#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int adc,T1,T2,T3,T4; 

void setup(){   
  lcd.begin(16, 2); 
  delay(1000); 
}

void loop(){
  adc = analogRead(0);    
  T1=(adc*5)/10;
  delay(100);
  adc = analogRead(1);    
  T2=(adc*5)/10;
  delay(100);
  adc = analogRead(2);    
  T3=(adc*5)/10;
  delay(100);
  adc = analogRead(3);    
  T4=(adc*5)/10;
  delay(100);
  
  lcd.setCursor(0, 0);
  lcd.print("T1=");  
  lcd.print(T1);
  lcd.print(" T2=");  
  lcd.print(T2);  
  lcd.setCursor(0, 1);
  lcd.print("T3=");  
  lcd.print(T3);
  lcd.print(" T4=");  
  lcd.print(T4);
  delay(1000);  
}

