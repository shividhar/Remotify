#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>

int delayTime=300;
char inputText[100];

void setup()
{
  Serial.begin(9600);
  volumeInitialize();
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
  volume();
  muteSwitch();
  playpauseButton();
  nextButton();
  
  if(serialEvent())
  {
    OrbitOledClear();
    OrbitOledClearBuffer();
    OrbitOledMoveTo(0, 0);
    OrbitOledDrawString(inputText);
    OrbitOledUpdate();
    memset(inputText,0,100);
  }
  
  Serial.println(9); //do nothing
  delay(delayTime*2);
  delayTime=50;
}

bool serialEvent()
{
  while (Serial.available()) {
    Serial.readBytesUntil('\n',inputText, 1000);
    return true;
  }
}
