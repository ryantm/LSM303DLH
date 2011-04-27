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
  Serial.print(compass.pitch());     // accelerometer X
  Serial.print("\t"); 
  Serial.print(compass.roll());      // accelerometer y
  Serial.print("\t");
  Serial.print(compass.heave());     // accelerometer z
  Serial.print("\t"); 
  Serial.println(compass.heading()); // compass heading
  delay(100); 
}




