#include <Wire.h>
#include <LSM303DLH.h>

// initialize the compass library:
LSM303DLH compass;

void setup() {
  Serial.begin(9600);
  //start the Wire library and enable the compass:
  Wire.begin();
  compass.enable();

  // calibrate for the first ten seconds after startup:
  while (millis() < 5000) {
    compass.calibrate(); 
  }
}  

void loop() {
  // read the compass and print the results:
  compass.read();
Serial.print("Pitch: ");           // X axis angle
  Serial.print(compass.pitch());     // X axis angle
  Serial.print("\tRoll: ");
  Serial.print(compass.roll());      // Y axis angle
  Serial.print("\tSurge: ");
  Serial.print(compass.surge());     // X axis acceleration
  Serial.print("\tSway: ");
  Serial.print(compass.sway());    // Y axis acceleration
  Serial.print("\tHeading: "); 
  Serial.println(compass.heading()); // compass heading
  delay(100); 
}




