#include <Wire.h>
#include <LSM303DLH.h>

LSM303DLH compass;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  compass.enable();
  
  // Calibration values. Use the serial example program to get the values for
  // your compass.
  compass.m_max.x = +540; compass.m_max.y = +500; compass.m_max.z = 180;
  compass.m_min.x = -520; compass.m_min.y = -570; compass.m_min.z = -770;
}

void loop() {
  compass.read();
  int heading = compass.heading((vector){0,-1,0});
  Serial.println(heading);
  delay(100);
}