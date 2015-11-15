#include <Wire.h>
#include <ADXL345.h>
const float alpha = 0.5;

double fXg = 0;
double fYg = 0;
double fZg = 0;

ADXL345 acc;

void setup()
{
acc.begin();
Serial.begin(1200);
delay(100);
}

void loop()
{
double pitch, roll, Xg, Yg, Zg;
acc.read(&Xg, &Yg, &Zg);

//Low Pass Filter to smooth out data
fXg = Xg * alpha + (fXg * (1.0 - alpha));
fYg = Yg * alpha + (fYg * (1.0 - alpha));
fZg = Zg * alpha + (fZg * (1.0 - alpha));

//Roll and Pitch Equations
roll = (atan2(-fYg, fZg)*180.0)/M_PI;
pitch = (atan2(fXg, sqrt(fYg*fYg + fZg*fZg))*180.0)/M_PI;

Serial.print(Xg);
Serial.print(" ");
Serial.print(Yg);
Serial.print(" ");
Serial.print(Zg);
Serial.print(" ");
Serial.print(pitch);
Serial.print(" ");
Serial.println(roll);

delay(50);
}

//[/sourcecode]

/*
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  
}
*/
