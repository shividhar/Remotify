const int leftSwitch=PA_6;
const int rightSwitch=PA_7;
const int switchCount=2;
const int switches[switchCount]={leftSwitch, rightSwitch};
bool switchState[2];

void switchInitialize()
{
  for(int i=0;i<switchCount;i++)
    pinMode(switches[i], INPUT);
    switchState[0]=digitalRead(switches[0]);
    switchState[1]=digitalRead(switches[1]);
}

void repeatToggle()
{
  if(digitalRead(switches[0])!=switchState[0])
  {
    switchState[0]=digitalRead(switches[0]);
    Serial.println("repeat");
  }
}

void muteToggle()
{
  if(digitalRead(switches[1])!=switchState[1])
  {
    switchState[1]=digitalRead(switches[1]);
    Serial.println("mute");
  }
}

