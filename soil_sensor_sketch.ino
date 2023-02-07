#include <eeprom.h>
int moisture = 0;
int moistureLevels[500];
int trigPin = 9;    // TRIG pin
int echoPin = 8;    // ECHO pin
float distance_cm;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
  int i = 0;
}

void loop()
{
  // Range Finding
  // 
  distance_cm = .01723 * readUltrasonicDistance();
  // convert to inches by dividing by 2.54
  // inches = (cm / 2.54);

  // Soil Sensing
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
long readUltrasonicDistance()
{
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin and calculate the distance
  return 0.017 * pulseIn(echoPin, HIGH);
}