
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
//SDA A4 SLC A%
 
  int smokeA0=A0;// Define the pin for the MQ-2 sensor
  const int DOUTpin=8;
  int smokeA1=A1;// Define the pin for the MQ4 sensor
  int smokeA2=A2;
  int smokeA3=A3;
  int led2 = 9;//MQ-2
  int led4 = 3;//MQ-4
  int led7 = 7;
  int led8 = 11;
  int sT1=80;
  int sT2=50;
  int sT3=80;
  int sT4=100; 
 

  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
  pinMode(smokeA0,INPUT);
  pinMode(smokeA1,INPUT);
  pinMode(smokeA2,INPUT);
  pinMode(smokeA3,INPUT);
  pinMode(led2,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogSensor1 = analogRead(smokeA0);
  int analogSensor2 = analogRead(smokeA1);
  int analogSensor3 = analogRead(smokeA2);
  int analogSensor4 = analogRead(smokeA3);
 
 
  Serial.println("Pin A0:");
  Serial.println(analogSensor1);
  //delay(2000);
  Serial.println("Pin A1:");
  Serial.println(analogSensor2);
  Serial.println("Pin A2:");
  Serial.println(analogSensor3);
  Serial.println("Pin A3:");
  Serial.println(analogSensor4);
  lcd.setCursor(2, 0);
  lcd.print("CO2: ");
  lcd.setCursor(2, 1);
  lcd.print("CH4: "); 
  lcd.setCursor(7, 0);
  lcd.print(analogSensor1);
  lcd.setCursor(7, 1);
  lcd.print(analogSensor2);
  lcd.print("CO: ");
  lcd.setCursor(2, 1);
  lcd.print("mq: "); 
  lcd.setCursor(7, 0);
  lcd.print(analogSensor3);
  lcd.setCursor(7, 1);
  lcd.print(analogSensor4);
  
if(analogSensor1 > sT1){
  analogWrite(led2,200);
  delay(1000);
  analogWrite(led2,0);
  delay(1000);
 analogWrite(led2,200);
  delay(1000);
//  digitalWrite(greenled,LOW);
}
else{
  analogWrite(led2,0);
//  digitalWrite(greenled,HIGH);
}
if(analogSensor3 > sT3){
    analogWrite(led7,250);
    delay(1000);
    analogWrite(led7,0);
    delay(1000);
    analogWrite(led7,250);
    delay(1000);
  }
  else{
    analogWrite(led7,0);
  }
  //warning for high temparature
 if(analogSensor2 > sT2){
  analogWrite(led4,200);
  delay(1000);
  analogWrite(led4,0);
  delay(1000);
 analogWrite(led4,200);
  delay(1000);
//  digitalWrite(greenled,LOW);
}
else{
  analogWrite(led4,0);
//  digitalWrite(greenled,HIGH);
}
if(analogSensor4 > sT4){
  analogWrite(led8,200);
  delay(1000);
  analogWrite(led8,0);
  delay(1000);
 analogWrite(led8,200);
  delay(1000);
//  digitalWrite(greenled,LOW);
}
else{
  analogWrite(led8,0);
//  digitalWrite(greenled,HIGH);
}
delay(10000);

}
