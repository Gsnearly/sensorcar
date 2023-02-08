/* 
  Created by Garrett Snearly from the arduino cloud for sensor car project

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  CloudLight backword;
  CloudLight forward;
  int speed;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
int m1pin1 = 0;
int m1pin2 = 1;

void setup() {
  Serial.begin(9600);
  delay(1500); 
  pinMode(m1pin1,OUTPUT);
  pinMode(m1pin2,OUTPUT);
  pinMode(2,OUTPUT);
  
  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

}

void loop() {
  ArduinoCloud.update();

}

void onForwardChange()  {
  if(forward == 1){
    analogWrite(2, speed);
    digitalWrite(m1pin1, LOW);
    digitalWrite(m1pin2, HIGH);
  }
  if(forward == 0){
    digitalWrite(m1pin1, LOW);
    digitalWrite(m1pin2, LOW);
  }
  }

void onBackwordChange()  {

if(backword == 1){
    analogWrite(2, speed);
    digitalWrite(m1pin1, HIGH);
    digitalWrite(m1pin2, LOW);
  }
  if(backword == 0){
    digitalWrite(m1pin1, LOW);
    digitalWrite(m1pin2, LOW);
  }
  }

void onSpeedChange()  {

}
