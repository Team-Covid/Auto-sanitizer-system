
// Libraries for I2C communication with the arduino
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//pin declarations
#define trigger 9 // pulse trigger
#define echo 8  // pulse note
#define led 13 // indicator for the operation of the sanitizer
#define pump 12 // pump signal
#define temp A0 // temperature reading
#define buzz 7 // alert creation

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
 
 
float time = 0;
float distance = 0;
 
void setup()
{
 lcd.init(); //Initialize the lcd
 lcd.backlight();
 pinMode(trigger, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(led, OUTPUT);
 pinMode(pump, OUTPUT);
 pinMode(buzz, OUTPUT);
}
 
void loop()
{
 measure_distance();
 if(distance < 10)
 {
   digitalWrite(LED, HIGH);
   digitalWrite(MOSFET,HIGH);
   tempData();
 }
 else
 {
   digitalWrite(LED,LOW);
   digitalWrite(MOSFET,LOW);
 }
 delay(500);
}

// ultrasonic sensor
void measure_distance()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 
 distance= time * 340 / 20000;
}
//  IR Temperature sensor
void tempData ()
{
  lcd.setCursor(0, 0);
  lcd.print(temp);
}
