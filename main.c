#include <math.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  Serial.begin(9600);
  
  // Motor control
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  
  // Mode Switch
  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  
  lcd_1.begin(16, 2);
  text_sequence();
  lcd_1.clear();
}

void loop()
{
  lcd_1.setCursor(0, 0);
  lcd_1.print("Select To");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Start    >>");
  
  int bt_13 = digitalRead(13);
  int bt_12 = digitalRead(12);

  if(bt_13 == 0){
  // instructions if bt_13 pressed
  }
  if(bt_12 == 0){
  // instructions if bt_12 pressed
  }
}

void normal_wash()
{
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  delay(1000);
  digitalWrite(4, HIGH);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  delay(1000);
}

void text_sequence()
{
  lcd_1.setCursor(0, 0);
  lcd_1.print("Washing");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Machine");
  delay(2000);
}
int timeRead()
{
  //lcd_1.setCursor(0, 0);
  int sensorValue = analogRead(A0);
  double minuites = sensorValue * (60.0 / 1023.0);
  /* // hold for further changes
  lcd_1.print(floor(minuites));
  lcd_1.setCursor(8, 0);
  lcd_1.print("minuites");
  */
  return minuites;
}