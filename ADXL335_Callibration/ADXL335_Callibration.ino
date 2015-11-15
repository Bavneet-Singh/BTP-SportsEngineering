const int xpin = 0;
const int ypin = 1;
const int zpin = 2;// analog: Z axis output from accelerometer

const float arduino_power_supply = 5;
const float sensor_power_supply = 3.3;
const float zero_g_bias = sensor_power_supply / 2;
 
void setup() {
 Serial.begin   (9600);
 Serial.print ("x axis g's");
 Serial.print ("\t");
 Serial.print ("y axis g's");
 Serial.print ("\t");
 Serial.print ("z axis g's");
 Serial.println();
 delay(1000);
}
void loop() {
 float voltage_x = (analogRead(xpin)) * arduino_power_supply / 1024;
 float x = (voltage_x - zero_g_bias) * 1000 / 330;
 Serial.print(x);
 Serial.print ("\t");
 
 float voltage_y = (analogRead(ypin)) * arduino_power_supply / 1024;
 float y = (voltage_y - zero_g_bias) * 1000 / 330;
 Serial.print(y);
 Serial.print ("\t");
 
 float voltage_z = (analogRead(zpin)) * arduino_power_supply / 1024;
 float z = (voltage_z - zero_g_bias) * 1000 / 330;
 Serial.print(z);
 
 Serial.println();
 delay(200);
}
