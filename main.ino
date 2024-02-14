#include <math.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  Serial.begin(9600);
  
  // Motor control
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  // Switches
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  
  // Initialize LCD
  lcd_1.begin(16, 2);
  start_text_sequence();
  lcd_1.clear();
}

void loop()
{
  lcd_1.setCursor(0, 0);
  lcd_1.print("Select To");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Start    >>");
  
  int time = 0;
  int bt_13 = digitalRead(13);
  int bt_12 = digitalRead(12);

  if(bt_13 == 0){
  // instructions if bt_13 pressed
    lcd_1.clear();
    do{
      timeRead();
      time = timeRead();
    }while(digitalRead(10) != 0);
    // 
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Washing...");
    
    for(int i = 0; i < time; i + 0.1)
    {
      spin_dry();
      if(digitalRead(6) == 0)
      {
        water_rel();
      }
      if(digitalRead(5) == 0)
      {
        water_stop();
      }
      if(digitalRead(11) == 0)
      {
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("Terminated");
        spin_terminate();
        delay(3000);
        lcd_1.clear();
        break;
      }
    }
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Finished");
    spin_terminate();
    delay(3000);
    lcd_1.clear();
  }
  if(bt_12 == 0){
  // instructions if bt_12 pressed
    lcd_1.clear();
    do{
      timeRead();
      time = timeRead();
    }while(digitalRead(10) != 0);
    // 
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Washing...");
    
    for(int i = 0; i < time; i + 0.1)
    {
      spin_wash();
      spin_wash_rev();
      if(digitalRead(6) == 0)
      {
        water_rel();
      }
      if(digitalRead(5) == 0)
      {
        water_stop();
      }
      if(digitalRead(11) == 0)
      {
        lcd_1.clear();
        lcd_1.setCursor(0, 0);
        lcd_1.print("Terminated");
        spin_terminate();
        delay(3000);
        lcd_1.clear();
        break;
      }
    }
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Finished");
    spin_terminate();
    delay(3000);
    lcd_1.clear();
  }
}
void spin_wash()
{
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);

}

void spin_wash_rev()
{
  digitalWrite(4, HIGH);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
}

void spin_dry()
{
  digitalWrite(4, HIGH);
}

void spin_terminate()
{
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
}

void water_rel()
{
  digitalWrite(7, HIGH);
}

void water_stop()
{
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void start_text_sequence()
{
  lcd_1.setCursor(0, 0);
  lcd_1.print("Washing");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Machine");
  delay(2000);
}
int timeRead()
{
  lcd_1.setCursor(0, 0);
  int sensorValue = analogRead(A0);
  double minuites = sensorValue * (60.0 / 1023.0);
  lcd_1.print(floor(minuites));
  lcd_1.setCursor(8, 0);
  lcd_1.print("minuites");

  return minuites;
}