const int leftSwitch=PA_6;
const int rightSwitch=PA_7;
const int switchCount=2;
const int switches[switchCount]={leftSwitch, rightSwitch};
bool switchState[switchCount];

void switchInitialize()
{
  for(int i=0;i<switchCount;i++)
    pinMode(switches[i], INPUT);
  switchState[0]=digitalRead(switches[0]);
  switchState[1]=digitalRead(switches[1]);
  repeatInitialize();
  muteInitialize();
}

void repeatInitialize()
{
  if(switchState[0])
      Serial.println(3); //repeatOn
  else
      Serial.println(4); //repeatOff
  delay(delayTime*3);
}

void repeatSwitch()
{
  if(digitalRead(switches[0])!=switchState[0])
  {
    switchState[0]=digitalRead(switches[0]);
    if(switchState[0])
      Serial.println(3); //repeatOn
    else
      Serial.println(4); //repeatOff
  }
  delay(delayTime);
}

void muteInitialize()
{
  if(switchState[1])
      Serial.println(5); //muteOn
  else
      Serial.println(6); //muteOff
  delay(delayTime);
}

void muteSwitch()
{
  if(digitalRead(switches[1])!=switchState[1])
  {
    switchState[1]=digitalRead(switches[1]);
    if(switchState[1])
      Serial.println(5); //muteOn
    else
      Serial.println(6); //muteOff
  }
  delay(delayTime);
}

