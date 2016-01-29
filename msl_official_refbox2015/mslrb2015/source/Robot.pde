//==============================================================================
//==============================================================================
class Robot {
  float guix, guiy;
  String state="play"; //play , repair , yellow, doubleyellow , red
  int waittime=-1;
  long DoubleYellowOut=0; 
  long DoubleYellowOutRemain=0; 

  Robot(float zx, float zy) {
    guix=zx; 
    guiy=zy;
  }

  //-------------------------------
  void reset_to_play() {
    state="play";
    waittime=-1;
  }
  void reset() {
    state="play";
    waittime=-1;
    this.DoubleYellowOut=0;
    this.DoubleYellowOutRemain=0; 
  }
  
  void setRstate(Robot r) {
    this.state=r.state;
    this.waittime=r.waittime;
    this.DoubleYellowOut=r.DoubleYellowOut;
  }
  
  void updateUI(color c, boolean UIleft) {
    stroke(c); 
    strokeWeight(2);
    color rcolor=255;
    if (this.state.equals("repair")) rcolor=Config.RobotRepairColor;
    if (this.state.equals("yellow")) rcolor=Config.RobotYellowCardColor;  //yellow  
    if (this.state.equals("doubleyellow")) rcolor=Config.RobotDoubleYellowCardColor;  //doubleyellow  
    if (this.state.equals("play")) rcolor=Config.RobotPlayColor;  //white (very light-green)
    if (this.state.equals("red")) rcolor=Config.RobotRedCardColor;  //red
    fill(rcolor);
    float tx=offsetRight.x+88+this.guix;
    float ty=offsetLeft.y+this.guiy;
    if (UIleft) tx=offsetLeft.x-128+this.guix;       
    ellipse(tx, ty, 32, 32);  
    fill(255);
    if (waittime>=0)  text(nf(waittime+1, 2), tx, ty);
  }
  
}
//==============================================================================
//==============================================================================
