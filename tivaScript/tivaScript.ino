#include <delay.h>
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
  volumeInit();
  switchInit();
  buttonInit();
  
  OrbitOledInit();
  OrbitOledSetDrawMode(modOledSet);

  WireInit();
  ShakeInit();
  LEDInit();

}

void loop()
{
  repeatSwitch();
  volume();
  muteSwitch();
  playpauseButton();
  nextButton();
  previousButton();
  shakeShuffler();
  
  if(serialEvent())
  {
    draw();
  }
  delayTime = 50;
}
