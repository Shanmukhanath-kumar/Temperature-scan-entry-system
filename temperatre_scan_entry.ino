#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,16,2);
int in=6;
int out=7;
int buzzer=8;
int red=10;
int green=9;
void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");  
  mlx.begin();  
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("      Welcome     ");
  delay(1000);
  lcd.clear();
  pinMode(in,INPUT);
  pinMode(out,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("T=");
  lcd.print(mlx.readObjectTempF());
people();
  delay(500);
lcd.clear();

  //Serial.print("*F\tObject = "); Serial.print(); Serial.println("*F");
lcd.clear();
}
int c=0;
int people(){
 
  float temp=mlx.readObjectTempF();
 int  x= digitalRead(in);
 int  y= digitalRead(out);
 
  if(x==1 && temp <=95 &&y==0){
    lcd.setCursor(0,1);
    lcd.print(" ALLOW");
    digitalWrite(green,HIGH);
    delay(500);
    lcd.clear();
    c++;
    digitalWrite(green,LOW);
  }
   if( y==1){
    c--;
      if(c<0){
        c=0;
      }
  }
 if(temp>=95){
  lcd.setCursor(0,0);
    lcd.print(" HIGH TEMP ");
      lcd.setCursor(1,0);
    lcd.print(" HIGH TEMP ");
    digitalWrite(red,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(500);
    lcd.clear();
    digitalWrite(red,LOW);
    digitalWrite(buzzer,LOW);
 }
 lcd.setCursor(0,8);
 lcd.print("Count=");
 lcd.print(c);
 delay(500);
if(c>5){
    lcd.setCursor(0,0);
    lcd.print(" room is full");
    digitalWrite(red,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(500);
    lcd.clear();
    digitalWrite(red,LOW);
    digitalWrite(buzzer,LOW);
  }
 
   lcd.clear();
 

}