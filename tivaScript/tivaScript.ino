#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>

#define delayTime 100
boolean stringComplete = false;
char inputText[100];

void setup() {
  Serial.begin(9600);
  switchInitialize();
  buttonInitialize();

  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();
  OrbitOledSetDrawMode(modOledSet);
  
  Serial.flush();   
}

void loop() {
  repeatSwitch();
  muteSwitch();
  playpauseButton();
  nextButton();

  if(stringComplete){
    OrbitOledClear();
    OrbitOledClearBuffer();
    OrbitOledMoveTo(0, 0);
    OrbitOledDrawString(inputText);
    OrbitOledUpdate();
    memset(inputText,0,100);
    stringComplete=false;
  }
  Serial.println(9); //do nothing
  delay(delayTime);
}

void serialEvent() {
  while (Serial.available()) {
    Serial.readBytesUntil('\n',inputText, 1000);
    stringComplete = true;
  }
}
