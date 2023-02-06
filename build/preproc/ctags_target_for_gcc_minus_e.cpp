# 1 "c:\\Users\\jortega\\Desktop\\River Project\\soil_sensor_sketch.ino"
// C++ code
int moisture = 0;
int moistureLevels[500];
void setup()
{
  pinMode(A0, 0x1);
  pinMode(A1, 0x0);
  Serial.begin(9600);
}

void loop()
{
  // Apply power to the soil moisture sensor
  digitalWrite(A0, 0x1);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  // Turn off the sensor to reduce metal corrosion
  // over time
  digitalWrite(A0, 0x0);
  Serial.println(moisture);
  delay(1000); // Wait for 100 millisecond(s)
}
