#define IR1 A0
#define IR2 A1
#define ledC1 2
#define ledC2 3
#define ledC3 4
#define ledC4 5
#define ledC5 6
#define ledC6 7
int a1;
     
//setting hours, minutes, secound  and miliseconds to 0
int h=0;     
int m=0;     
int s=0;     
int ms=0;    

//defines pin for all buttons
const int startPin = 3;    
const  int stopPin = 4;    
const int resetPin = 5;   
    
//defines starting  points
int start=0;     
int stop1=0;
int reset=0;


void stopwatch()
{
  ms=ms+10;           
  delay(10); 
   
 if(ms==590)           
  {
   
   ms=0; 
   s=s+1; 
  }
  
  if(s==60)     //if state for counting up minutes
  { 
  s=0; 
  m=m+1; 
  }

  if(m==60)      //if state for counting up hours
  {  
  m=00; 
  h=h+01;  
  } 
   
   

   stop1 = digitalRead(stopPin);  //reading buton  state
 if(stop1 == HIGH)    //checking if button is pressed
 {
  stopwatch_stop();   //calls the stopwatch_stop function
 }
  else
  {
   stopwatch();    //calls the stopwatch function
  }
}

void stopwatch_stop()
{       
   start = digitalRead(startPin);   //reading buton state
 if(start == HIGH)
 {
  stopwatch();    //calls  the stopwatch function
 } 
 
 reset = digitalRead(resetPin);   //reading  buton state
 if(reset == HIGH)
 {
   stopwatch_reset();    //calls the  stopwatch_reset function
   loop();
  }
 if(reset == LOW)
 {
  stopwatch_stop();    //calls the stopwatch_stop function
 }
}

void stopwatch_reset()
{
 h=00;    //seting hours to 0
 m=00;    //seting minutes to 0
  s=00;    //seting seconds to 0
 return;  //exiting the program and returning  to the point where entered the program
}




void setup() 
{  
  Serial.begin(9600);
  // Set pin 8 t/m 10 as output
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  // Set all output to LOW in order to turn all LEDs off
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  
} 
void loop() 
{ 
  
 
}
  








