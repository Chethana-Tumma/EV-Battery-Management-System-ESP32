#define BLYNK_TEMPLATE_ID "TMPL33qF-KQIX"
#define BLYNK_TEMPLATE_NAME "EV BMS"
#define BLYNK_AUTH_TOKEN "BjQ6QxLqok9LjPMY7JRBA8lMQctn73Am"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define CELL1 32
#define CELL2 35
#define CELL3 34

#define RED_LED 2
#define GREEN_LED 4
#define YELLOW_LED 5
#define BUZZER 18
#define RELAY 12

float v1, v2, v3, avg;
int p1, p2, p3;

String status;
int statuscode;

LiquidCrystal_I2C lcd(0x27, 16, 2);

float readVoltage(int pin)
{
  int rawvalue= analogRead(pin);
  return(rawvalue / 4095.0) *3.3;
}

int getPercent(float v)
{
  return constrain(map(v * 100, 0, 330, 0, 100), 0, 100);
}


void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("-- BATTERY MANAGEMENT SYSTEM ACTIVATED --");
}

void loop()
{
  v1= readVoltage(CELL1);
  v2= readVoltage(CELL2);
  v3= readVoltage(CELL3);
  avg= (v1 + v2 + v3) / 3.0;


  p1= getPercent(v1);
  p2= getPercent(v2);
  p3= getPercent(v3);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(BUZZER, LOW);




  if (p1 < 30 || p2 < 30 || p3 < 30)
  {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    digitalWrite(RELAY, HIGH);
    status= "LOW";

    delay(1000);
  }
  else if (p1 > 80 && p2 > 80 && p3 > 80)
  {
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    digitalWrite(RELAY, HIGH);
    status= "HIGH";

    delay(1000);
  }
  else
  {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RELAY, LOW);
    status= "NORMAL";
    
    delay(1000);
  }

  Serial.println("--------------------------");

  Serial.print("P1 : ");
  Serial.print(p1);
  Serial.print(" || ");
  Serial.print("P2 : ");
  Serial.print(p2);
  Serial.print(" || ");
  Serial.print("P3 : ");
  Serial.println(p3);


  Serial.print("C1 :");
  Serial.println(v1);

  Serial.print("C2 :");
  Serial.println(v2);

  Serial.print("C3 :");
  Serial.println(v3);

  Serial.println(status);

lcd.init();
lcd.backlight();

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("C1 :");
  lcd.print(v1, 1);
  lcd.print("C2 :");
  lcd.print(v2, 1);

  lcd.setCursor(0,1);
  lcd.print("C3 :");
  lcd.print(v3, 1);
  lcd.print(" ");
  lcd.print(status);


  Blynk.virtualWrite(V0, avg);
  Blynk.virtualWrite(V1, v1);
  Blynk.virtualWrite(V2, v2);
  Blynk.virtualWrite(V3, v3);
  Blynk.virtualWrite(V4, status);

Blynk.run();  
delay(1000);
}
