uint32_t bottomButton=PD_2;
uint32_t topButton=PE_0;
uint32_t rightButton=PF_0;
const int buttonCount=3;
uint32_t buttons[buttonCount]={topButton, bottomButton, rightButton};
bool toggle = false;

struct buttonState
{ 
  bool state;
  bool prevState;
};

struct buttonState buttonStates[buttonCount];

void buttonInitialize()
{
  for(int i=0;i<buttonCount;i++)
    pinMode(buttons[i], INPUT);
}

void playPauseInitialize(){
  //Init Pause Button
  OrbitOledMoveTo(15,15);
  OrbitOledDrawRect(18, 25);
  OrbitOledMoveTo(20,15);
  OrbitOledDrawRect(23, 25);
  OrbitOledUpdate();  
}

void playpauseButton()
{
  buttonStates[0].state=digitalRead(buttons[0]);
  if(buttonStates[0].state && !buttonStates[0].prevState)
  {
    toggle=!toggle;
    Serial.println(0); //playpause
    draw();
    delay(delayTime);
  }
  buttonStates[0].prevState=buttonStates[0].state;
}

void nextButton()
{
  buttonStates[1].state=digitalRead(buttons[1]);
  if(buttonStates[1].state && !buttonStates[1].prevState)
  {
    Serial.println(1); //next
    if(toggle) //if the pause icon is shown, show play as new track plays
      toggle=!toggle;
    draw();
    delay(delayTime);
  }
  buttonStates[1].prevState=buttonStates[1].state;
}

void previousButton()
{
  buttonStates[2].state=!digitalRead(buttons[2]);
  if(buttonStates[2].state && !buttonStates[2].prevState)
  {
    Serial.println(2); //previous
    if(toggle) //if the pause icon is shown, show play as new track plays
      toggle=!toggle;
    draw();
    delay(delayTime);
  }
  buttonStates[2].prevState=buttonStates[2].state;
}

