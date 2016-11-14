void draw(){
  OrbitOledClear();

  int songLength;
  int artistLength;
  for(int i = 0; i < inputLength; i++){
    if(inputText[i] == '~'){
      songLength = i;
      artistLength = inputLength-(i+1);
    }
  }
  char song[songLength];
  
  char artist[artistLength];

  memcpy(song, inputText, songLength);
  memcpy(artist, inputText+songLength+1, artistLength); 
  
  OrbitOledMoveTo(0, 0);
  OrbitOledDrawString(song);
  OrbitOledMoveTo(0, 10);
  OrbitOledDrawString(artist);
  int startPosX = 0;
  int startPosY = 21;
  if(!toggle){
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledLineTo(startPosX,startPosY+10);
    OrbitOledMoveTo(startPosX,startPosY+10);
    OrbitOledLineTo(startPosX+10,startPosY+5);
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledLineTo(startPosX+12,startPosY+6);
  }else{
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledDrawRect(startPosX+3, startPosY+10);
    OrbitOledMoveTo(startPosX+5,startPosY);
    OrbitOledDrawRect(startPosX+8, startPosY+10);
  }
  
  OrbitOledUpdate();
}
