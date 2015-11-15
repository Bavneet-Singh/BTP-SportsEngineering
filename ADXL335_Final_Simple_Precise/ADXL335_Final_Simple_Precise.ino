//Analog read pins
const int xPin = 0;
const int yPin = 1;
const int zPin = 2;

//to hold the caculated values
double x;
double y;
double z;

void setup(){
  Serial.begin(9600); 
}

void loop(){
  
  //read the analog values from the accelerometer
  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);
  int zRead = analogRead(zPin);

  //Output the caculations
  Serial.print("x: ");
  Serial.print(xRead);
  Serial.print(" | y: ");
  Serial.print(yRead);
  Serial.print(" | z: ");
  Serial.println(zRead);

  delay(100);//just here to slow down the serial output - Easier to read
}
