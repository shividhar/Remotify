extern "C" {
#include <delay.h>
#include <FillPat.h>
#include <I2CEEPROM.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
}

int delayTime=300;
char inputText[100];
bool initialize = false;

void setup()
{
  initialize = true;
  Serial.begin(9600);
  volumeInitialize();
  switchInitialize();
  buttonInitialize();

  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();
  OrbitOledSetDrawMode(modOledSet);
  
  playPauseInitialize();
  Serial.flush();   
}

void loop() {
  if(initialize){
    Serial.println(1);
    initialize = false;
  }
  repeatSwitch();
  volume();
  muteSwitch();
  playpauseButton();
  nextButton();

  if(serialEvent())
  {
    draw();
  }
  Serial.println(9); //do nothing
  delay(delayTime*2);
  delayTime=50;
}

bool serialEvent()
{
  while (Serial.available()) {
    memset(inputText, 0, 100);
    Serial.readBytesUntil('\n',inputText, 1000);
    return true;
  }
}
