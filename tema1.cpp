#define buttonStart 2
#define buttonStop 3
#define ledRGB_Red 6
#define ledRGB_Green 5
#define ledRGB_Blue 4
#define led1 10
#define led2 9
#define led3 8
#define led4 7
#include <Arduino.h>
 
bool ok = 0;
 
unsigned long lastDebounceTimeStart = 0;
unsigned long lastDebounceTimeStop = 0;
unsigned long debounceDelay = 50;
 
bool isCharging = false;
bool isButtonPressedStart = false;
bool isButtonPressedStop = false;
int chargeLevel = 0;
 
void setup() {
  pinMode(buttonStart, INPUT);
  pinMode(buttonStop, INPUT);
  pinMode(ledRGB_Red, OUTPUT);
  pinMode(ledRGB_Green, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
 
  // Initial state: RGB LED should be green at the start
  digitalWrite(ledRGB_Green, HIGH);
  digitalWrite(ledRGB_Blue, LOW);  
  digitalWrite(ledRGB_Red, LOW);  
     // Red OFF
}
 
 
void loop() {
  if (digitalRead(buttonStart) == LOW) {
    ok = true; 
    delay(200); 
  }
 
  if (digitalRead(buttonStop) == LOW && ok) {
    ok = false; 
    stopCharging();
  }
 
  if (ok) {
    startCharging(); 
    ok=false;
  }
}
 
void startCharging() {
  isCharging = true;
 
  // Change RGB LED to red when charging starts
  digitalWrite(ledRGB_Green, LOW);
  digitalWrite(ledRGB_Blue, LOW);  // Green OFF
  digitalWrite(ledRGB_Red, HIGH);   // Red ON
 
  for (int i = 1; i <= 4 && ok; i++) {
    blinkLed(i);
  }
 
  finishCharging();
}
 
void blinkLed(int ledNumber) {
  int ledPin;
  switch (ledNumber) {
    case 1: ledPin = led1; break;
    case 2: ledPin = led2; break;
    case 3: ledPin = led3; break;
    case 4: ledPin = led4; break;
  }
 
  unsigned long blinkDuration = 3000;  // Total time for the LED to blink (3 seconds)
  unsigned long blinkInterval = 500;   // On/Off time for each blink (500ms)
  unsigned long startTime = millis();  // Record the start time of blinking
 
  while (millis() - startTime < blinkDuration) {
    digitalWrite(ledPin, HIGH);
    delay(blinkInterval);  // LED ON for 500ms
    digitalWrite(ledPin, LOW);
    delay(blinkInterval);  
     if (digitalRead(buttonStop) == LOW) {
    ok = false; 
    return;
  }// LED OFF for 500ms
  }
 
  digitalWrite(ledPin, HIGH); // LED stays ON after blinking
}
 
void finishCharging() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    delay(500);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    delay(500);
  }
 
  // Reset station
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(ledRGB_Green, HIGH);  // Green ON when charging finishes
  digitalWrite(ledRGB_Red, LOW);     // Red OFF
  isCharging = false;
}
 
void stopCharging() {
  finishCharging();
}