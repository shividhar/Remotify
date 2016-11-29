uint32_t leftSwitch = PA_6;
uint32_t rightSwitch = PA_7;
const int switchCount = 2;
uint32_t switches[switchCount] = {leftSwitch, rightSwitch};
bool switchState[switchCount];

void switchInit()
{
  for(int i = 0; i < switchCount; i++)
    pinMode(switches[i], INPUT);
  //set starting states as incorrect
  //forces first run to correct switch vs. computer inconsistencies
  switchState[0] = !digitalRead(switches[0]);
  switchState[1] = !digitalRead(switches[1]);
}

void repeatSwitch()
{ 
  if(digitalRead(switches[0])!=switchState[0])
  {
    switchState[0] = digitalRead(switches[0]);
    if(switchState[0])
      Serial.println('d'); //repeatOn
    else
      Serial.println('e'); //repeatOff
  }
  delay(delayTime);
}

void muteSwitch()
{
  if(digitalRead(switches[1])!=switchState[1])
  {
    switchState[1] = digitalRead(switches[1]);
    if(switchState[1])
      Serial.println('f'); //muteOn
    else
      Serial.println('g'); //muteOff
  }
  delay(delayTime);
}

