#include <delay.h>
//#include <stdlib.h>
//#include <OrbitBoosterPackDefs.h>
//#include <OrbitOled.h>
//#include <OrbitOledGrph.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <stdlib.h>

int delayTime = 300;
int previousVolume = -1;

void WireInit();
void ShakeInit();

void ShakeTick();

void setup()
{
  Serial.begin(9600);
  volumeInitialize();
  switchInitialize();
  buttonInitialize();
  
  OrbitOledInit();
  OrbitOledSetDrawMode(modOledSet);

  WireInit();
  ShakeInit();
  //Serial.flush();   
}

void loop()
{
  repeatSwitch();
  volume();
  muteSwitch();
  playpauseButton();
  nextButton();
  previousButton();

  shakeInitialize();
  
  if(serialEvent())
  {
    draw();
  }
  delayTime = 50;
}
