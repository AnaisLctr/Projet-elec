//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int pin_SENSOR = 11;
int sensorState = 0;
int score = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pin_SENSOR, INPUT);

  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  
}


void loop(){
  lcd.setCursor(1,0);
  lcd.print("BASKOBOLIDE :)");
  lcd.setCursor(2,1);
  lcd.print("Score : ");
  lcd.setCursor(10,1);
  lcd.print(score);
  sensorState = digitalRead(pin_SENSOR);
  if (sensorState == HIGH){
    score++;
    
    Serial.println(score);
    lcd.setCursor(10,1);
    lcd.print(score);
  }
}