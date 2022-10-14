import processing.serial.*;

int xx, yy, Switch;

int lf = 10;    // Linefeed in ASCII
String myString = null;
Serial myPort;  // The serial port
 String[] cool;
 
 
void setup() {
  size(500,500);
  // List all the available serial ports
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 115200);
  myPort.clear();
  // Throw out the first reading, in case we started reading 
  // in the middle of a string from the sender.
  myString = myPort.readStringUntil(lf);

}

void draw() {
  myString = ", ,";
  rect(511-yy, xx, 10, 10);
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil(lf);
    if (myString != null) {
      try{
      //println(myString);
      cool = split(myString, " ");
      println(Integer.valueOf(cool[1]));
          xx=Integer.valueOf(cool[1])/2;
          yy=Integer.valueOf(trim(cool[2]))/2;
          Switch=Integer.valueOf(cool[0]);
         //printArray(cool);
      } catch(Exception e){
      }
      if (Switch == 1){
       fill(255);
      }else{
      fill(#41F71E);
    }

      
    }
    
  }

}
