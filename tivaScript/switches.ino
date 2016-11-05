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
    muteInitialize();
    repeatInitialize();
}

void repeatInitialize()
{
  if(switchState[0])
      Serial.println("repeatOn");
  else
      Serial.println("repeatOff");
  delay(10);
}

void repeatSwitch()
{
  if(digitalRead(switches[0])!=switchState[0])
  {
    switchState[0]=digitalRead(switches[0]);
    if(switchState[0])
      Serial.println("repeatOn");
    else
      Serial.println("repeatOff");
  }
  delay(10);
}

void muteInitialize()
{
  if(switchState[1])
      Serial.println("muteOn");
  else
      Serial.println("muteOff");
  delay(10);
}

void muteSwitch()
{
  if(digitalRead(switches[1])!=switchState[1])
  {
    switchState[1]=digitalRead(switches[1]);
    if(switchState[1])
      Serial.println("muteOn");
    else
      Serial.println("muteOff");
  }
  delay(10);
}

