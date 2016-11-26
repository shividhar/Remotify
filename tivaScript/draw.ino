#define inputLength 200
char inputText[inputLength] = {0};

bool serialEvent()
{
  while(Serial.available())
  {
    memset(inputText, 0, inputLength);
    Serial.readBytesUntil('\n',inputText, 1000);
    return true;
  }
}

void draw()
{
  OrbitOledClearBuffer();
  drawPlayPause();
  drawVolume();  
  drawRemotifyLogo();
  drawSongData();
  OrbitOledUpdate();
}

void drawPlayPause()
{
  int startPosX = 0;
  int startPosY = 21;
  if(toggle)
  {
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledLineTo(startPosX,startPosY+10);
    OrbitOledMoveTo(startPosX,startPosY+10);
    OrbitOledLineTo(startPosX+10,startPosY+5);
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledLineTo(startPosX+12,startPosY+6);
  }
  else
  {
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledDrawRect(startPosX+3, startPosY+10);
    OrbitOledMoveTo(startPosX+5,startPosY);
    OrbitOledDrawRect(startPosX+8, startPosY+10);
  }  
}

void drawSongData()
{
  int songLength = 0;
  int artistLength = 0;
  for(int i = 0; i < inputLength; i++)
  {
    if(inputText[i] == '~')
    {
      songLength = i;
      artistLength = inputLength-(i+1);
    }
  }
  char song[songLength];
  char artist[artistLength];
  if(songLength)
  {
    memcpy(song, inputText, songLength);
    memcpy(artist, inputText+songLength+1, artistLength); 
    OrbitOledMoveTo(0, 0);
    OrbitOledDrawString(song);
    OrbitOledMoveTo(0, 10);
    OrbitOledDrawString(artist);
  }else
  {
    OrbitOledClearBuffer();
    OrbitOledMoveTo(0, 10);
    OrbitOledDrawString("Welcome to");
    OrbitOledMoveTo(0, 20);
    OrbitOledDrawString("Remotify!");
  }  
}

void drawVolume()
{
  int bars = 0;
  if(0 < previousVolume && previousVolume < 20)
    bars = 1;
  else if(20 <= previousVolume && previousVolume < 40)
    bars = 2;
  else if(40 <= previousVolume && previousVolume < 60)
    bars = 3;  
  else if(60 <= previousVolume && previousVolume < 80)
    bars = 4;
  else if(80 <= previousVolume && previousVolume <= 100)
    bars = 5;  
  else
    bars = 0;

  int rectangleStartX = 15;
  int rectangleStartY = 30;
  
  for(int i = 1; i <= bars; i++)
  {
    OrbitOledMoveTo(rectangleStartX,rectangleStartY);
    OrbitOledDrawRect(rectangleStartX + 1, rectangleStartY+(i*2));
    rectangleStartX = rectangleStartX + 3;
    rectangleStartY = rectangleStartY - 2;
  }
}

void drawRemotifyLogo(){
  OrbitOledMoveTo(35, 24);
  OrbitOledDrawString("Remotify!");
}
