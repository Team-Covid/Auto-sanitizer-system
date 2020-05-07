// Libraries for I2C communication with the arduino as well as the mlx temperature sensor.
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>


//pin declarations
#define trigger 9 // pulse trigger
#define echo 8  // pulse note
#define led 13 // indicator for the operation of the sanitizer
#define pump 12 // pump signal
#define buzz 7 // alert creation

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();


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
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");
  mlx.begin();
  lcd.home();
}

void loop()
{
  measure_distance();
  if (distance < 10)
  {
    digitalWrite(led, HIGH);
    digitalWrite(pump, HIGH);
    tempData();
  }
  else
  {
    digitalWrite(led, LOW);
    digitalWrite(pump, LOW);
  }
  delay(500);
}

// ultrasonic sensor
void measure_distance()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  time = pulseIn(echo, HIGH);

  distance = time * 340 / 20000;
}
//  IR Temperature sensor
void tempData ()
{
  float temp = mlx.readObjectTempC();
  lcd.home();
  lcd.print(temp);
  if (temp > 22.0)
  {
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(buzz, LOW);
    delay(100);
  }
  else
  {
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
  }
}
