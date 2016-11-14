uint32_t bottomButton=PD_2;
uint32_t topButton=PE_0;
const int buttonCount=2;
const int buttons[buttonCount]={topButton, bottomButton};
bool toggle = false;

struct buttonState
{ 
  bool state;
  bool prevState;
  bool isRising;
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
  bool currentState=digitalRead(buttons[0]);

  if(currentState && !buttonStates[0].prevState){
    if(toggle){
      toggle = false;
    }else{
      toggle = true;
    }
    Serial.println(0); //playpause
    draw();
    delay(delayTime);
  }
  buttonStates[0].prevState=currentState;
}

void nextButton()
{
  bool previousState=buttonStates[1].state;
  buttonStates[1].state=digitalRead(buttons[1]);
  buttonStates[1].isRising=(!previousState && buttonStates[1].state);
  if(buttonStates[1].isRising)
  {
    Serial.println(1); //next
    draw();
    delay(delayTime);
  }
}
