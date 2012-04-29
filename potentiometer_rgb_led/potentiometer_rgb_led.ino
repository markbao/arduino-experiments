/*

Vary a RGB LED with inputs from potentiometers.

R: twist/dial potentiometer
G: soft pot
B: flex pot

Licensed under public domain.

*/

// declare sensors
int rSensorPin = A0;
int gSensorPin = A1;
int bSensorPin = A2;

// store sensor values
int rSensorValue = 0;
int gSensorValue = 0;
int bSensorValue = 0;

// declare LED pins
int rLedPin = 9;
int gLedPin = 10;
int bLedPin = 11;

// store intensities
int rIntensity = 0;
int gIntensity = 0;
int bIntensity = 0;

// delay time
int delayTime = 50;

void setup() {
  // delcare ledPins as OUTPUTs
  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  
  // declare rSensorPins as inputs
  pinMode(rSensorPin, INPUT);
  pinMode(gSensorPin, INPUT);
  pinMode(rSensorPin, INPUT);
  
  // start the serial port
  Serial.begin(9600);
}

void loop() {
  // read sensor values
  rSensorValue = analogRead(rSensorPin);
  gSensorValue = analogRead(gSensorPin);
  bSensorValue = analogRead(bSensorPin);
  
  // scale the three and set intensities
  rIntensity = map(rSensorValue, 0, 1024, 0, 255);
  gIntensity = map(gSensorValue, 0, 1024, 0, 255);
  bIntensity = map(bSensorValue, 180, 320, 0, 255);
  
  // print
  Serial.println(0);
  Serial.println(rIntensity);
  Serial.println(gIntensity);
  Serial.println(bIntensity);
  
  // write to light level
  analogWrite(rLedPin, rIntensity);
  analogWrite(gLedPin, gIntensity);
  analogWrite(bLedPin, bIntensity);
  
  delay(delayTime);
}
