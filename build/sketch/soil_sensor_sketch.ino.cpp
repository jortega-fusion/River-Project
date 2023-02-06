#include <Arduino.h>
#line 1 "c:\\Users\\jortega\\Desktop\\River Project\\soil_sensor_sketch.ino"
// C++ code
int moisture = 0;
int moistureLevels[500];
#line 4 "c:\\Users\\jortega\\Desktop\\River Project\\soil_sensor_sketch.ino"
void setup();
#line 11 "c:\\Users\\jortega\\Desktop\\River Project\\soil_sensor_sketch.ino"
void loop();
#line 4 "c:\\Users\\jortega\\Desktop\\River Project\\soil_sensor_sketch.ino"
void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // Apply power to the soil moisture sensor
  digitalWrite(A0, HIGH);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  // Turn off the sensor to reduce metal corrosion
  // over time
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  delay(1000); // Wait for 100 millisecond(s)
}
