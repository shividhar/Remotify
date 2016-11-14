void draw(){
  OrbitOledClear();
  
  OrbitOledMoveTo(0, 0);
  OrbitOledDrawString(inputText);

  if(toggle){
    int startPosX = 15;
    int startPosY = 15;
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledLineTo(startPosX,startPosY+10);
    OrbitOledMoveTo(startPosX,startPosY+10);
    OrbitOledLineTo(startPosX+10,startPosY+5);
    OrbitOledMoveTo(startPosX,startPosY);
    OrbitOledLineTo(startPosX+12,startPosY+6);
  }else{
    OrbitOledMoveTo(15,15);
    OrbitOledDrawRect(18, 25);
    OrbitOledMoveTo(20,15);
    OrbitOledDrawRect(23, 25);
  }
  
  OrbitOledUpdate();
}
