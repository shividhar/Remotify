uint32_t bottomButton=PD_2;
uint32_t topButton=PE_0;
const int buttonCount=2;
const int buttons[buttonCount]={topButton, bottomButton};

struct buttonState
{ 
  bool state;
  bool isRising;
};

struct buttonState buttonStates[buttonCount];

void buttonInitialize()
{
  for(int i=0;i<buttonCount;i++)
    pinMode(buttons[i], INPUT);
}

void playpauseButton()
{
  bool previousState=buttonStates[0].state;
  buttonStates[0].state=digitalRead(buttons[0]);
  buttonStates[0].isRising=(!previousState && buttonStates[0].state);
  if(buttonStates[0].isRising)
  {
    Serial.println(0); //playpause
    delay(delayTime);
  }
}

void nextButton()
{
  bool previousState=buttonStates[1].state;
  buttonStates[1].state=digitalRead(buttons[1]);
  buttonStates[1].isRising=(!previousState && buttonStates[1].state);
  if(buttonStates[1].isRising)
  {
    Serial.println(1); //next
    delay(delayTime);
  }
}
