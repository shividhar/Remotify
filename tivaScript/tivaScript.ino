#include <delay.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledGrph.h>

int delayTime = 300;
int previousVolume = -1;

void setup()
{
  Serial.begin(9600);
  volumeInitialize();
  switchInitialize();
  buttonInitialize();
  
  OrbitOledInit();
  OrbitOledSetDrawMode(modOledSet);
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
  if(serialEvent())
  {
    draw();
  }
  delayTime = 50;
}
