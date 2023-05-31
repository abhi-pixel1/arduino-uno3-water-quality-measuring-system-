#define ph_sensor A0
float ph_value,sensor_value=0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    ph_value = analogRead(ph_sensor);
    sensor_value = (ph_value)/7;

    Serial.print("ph = ");
    Serial.print(ph_value);
    Serial.println(sensor_value);
    delay(1000);
}