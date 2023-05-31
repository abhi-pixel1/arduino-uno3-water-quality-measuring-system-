#include <OneWire.h>
 #include <DallasTemperature.h>


 #define ONE_WIRE_BUS 7

 OneWire oneWire(ONE_WIRE_BUS);

 DallasTemperature sensors(&oneWire);

 int sensorPin = A0; //A0 FOR ARDUINO/ 36 FOR ESP
 float Celsius = 0;
 float Fahrenheit = 0;

#define ph_sensor A1


float ph_value,sensor_value=0;

void setup() {
  sensors.begin();
  Serial.begin(9600);
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
     Serial.print(" its CLEAR ");
   }
   if ((turbidity > 20) && (turbidity < 50)) {
     Serial.print(" its CLOUDY ");
   }
   if (turbidity > 50) {
     Serial.print(" its DIRTY ");
   }
   delay(3000);

  ph_value=analogRead(ph_sensor);
  sensor_value=(ph_value/7);
  Serial.print("ph_value = ");
  Serial.println(sensor_value);
  Serial.print(ph_value);
  delay(1000);
  
}