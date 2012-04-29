/*

Alternate a RGB LED when a piezo senses noise

Licensed under public domain.

*/

// declare sensors
int piezoSensorPin = A0;

// store sensor values
int piezoSensorValue = 0;

// declare LED pins
int rLedPin = 9;
int gLedPin = 10;
int bLedPin = 11;

// store intensities
int rIntensity = 0;
int gIntensity = 0;
int bIntensity = 0;

// store currently lit - 0 r, 1 g, 2 b
int currentRGB = 2;

// delay time
int delayTime = 100;

void setup() {
  // delcare ledPins as OUTPUTs
  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  
  pinMode(piezoSensorPin, INPUT);
  
  // start the serial port
  Serial.begin(9600);
}

void loop() {
  
  piezoSensorValue = analogRead(piezoSensorPin);
  Serial.println(piezoSensorValue);
  
  delay(delayTime);
}
