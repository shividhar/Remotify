#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>

#define inputLength 200

int delayTime=300;
char inputText[inputLength]={0};
int previousVolume=-1;

void setup()
{
  Serial.begin(9600);
  volumeInitialize();
  switchInitialize();
  buttonInitialize();

  OrbitOledInit();
  OrbitOledSetDrawMode(modOledSet);

  playPauseInitialize();
  Serial.flush();
}

void loop() {
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
  delayTime=50;
}

bool serialEvent()
{
  while (Serial.available()) {
    memset(inputText, 0, inputLength);
    Serial.readBytesUntil('\n',inputText, 1000);
    return true;
  }
}
