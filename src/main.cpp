//I, Cameron Randall, 000820614 guanantee that this is my work and my work only.

#include <Arduino.h>

//switch state
int lightSwitch = HIGH;
//persistant button state
int buttonSignal;


void setup() {
    // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 

  analogWriteRange(1023); 
}

void loop() {;
  //read button signal
  int buttonRead = digitalRead(D5);

  //read analog/dimmer signal
  int iVal = analogRead(A0);
  //if button signal doesn't match saved button signal
  if (buttonRead != buttonSignal) {
    //set savged signal to current signal
    buttonSignal = buttonRead;
    //if saved signal is pressed
    if (buttonSignal == HIGH) {
      //invert flag
      lightSwitch = !lightSwitch;
    }
  }

  //turn light on or off based on switch
  if (lightSwitch) {
    analogWrite(D4, iVal);
  } else {
    digitalWrite(D4, HIGH);
  }

  delay(1);
}