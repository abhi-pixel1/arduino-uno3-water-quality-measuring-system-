 #include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

 #define ONE_WIRE_BUS 7

 OneWire oneWire(ONE_WIRE_BUS);

 DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27,16,2);

 int sensorPin = A0; //A0 FOR ARDUINO/ 36 FOR ESP
 float Celsius = 0;
 float Fahrenheit = 0;

#define ph_sensor A1


float ph_value,sensor_value=0;

void setup() {
  sensors.begin();
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  // lcd.setCursor(1,0);   //Set cursor to character 2 on line 0
  // lcd.print("Hello world!");  
}

void loop() {
   sensors.requestTemperatures();
   int sensorValue = analogRead(sensorPin);
   Celsius = sensors.getTempCByIndex(0);
   Fahrenheit = sensors.toFahrenheit(Celsius);

   Serial.print(Celsius);
   Serial.print(" C  ");
   Serial.print(Fahrenheit);
   Serial.println(" F");
   Serial.println(sensorValue);
   int turbidity = map(sensorValue, 0, 750, 100, 0);
   delay(100);
   if (turbidity < 20) {
    lcd.setCursor(1,0);   //Set cursor to character 2 on line 0
    lcd.print("CLEAR");
    Serial.print(" its CLEAN ");    
   }
   if ((turbidity > 20) && (turbidity < 50)) {
     lcd.setCursor(1,0);   //Set cursor to character 2 on line 0
     lcd.print("CLOUDY");
     Serial.print(" its CLOUDY ");
   }
   if (turbidity > 50) {
     lcd.setCursor(1,0);   //Set cursor to character 2 on line 0
     lcd.print("DIRTY");
     Serial.print(" its DIRTY ");
   }
   delay(3000);

  ph_value=analogRead(ph_sensor);
  sensor_value=(ph_value/7);
  Serial.print("ph_value = ");
  Serial.println(sensor_value);
  Serial.print(ph_value);

  lcd.setCursor(1,1);   //Set cursor to character 2 on line 0
  lcd.print(Celsius);

  lcd.setCursor(7,1);  
  lcd.print(ph_value);
  // lcd.clear();
  
  delay(1000);
  
}