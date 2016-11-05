#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>

boolean stringComplete = false;
char inputText[100];

void setup() {
  Serial.begin(9600);
  switchInitialize();

  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();
  OrbitOledSetDrawMode(modOledSet);
  
  Serial.flush();   
}

void loop() {
  repeatSwitch();
  muteSwitch();
  if(stringComplete){
    OrbitOledClear();
    OrbitOledClearBuffer();
    OrbitOledMoveTo(0, 0);
    OrbitOledDrawString(inputText);
    OrbitOledUpdate();
    memset(inputText,0,100);
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    Serial.readBytesUntil('\n',inputText, 1000);
    stringComplete = true;
  }
}
