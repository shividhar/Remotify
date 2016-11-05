#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>

void switchInitialize();
void repeatToggle();
void muteToggle();

boolean stringComplete = false;
char inputText[100];

void setup() {
  
  switchInitialize();
  
  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();
  OrbitOledSetDrawMode(modOledSet);
  Serial.begin(9600);
  Serial.flush();   
}

void loop() {
  repeatToggle();
  muteToggle();
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
