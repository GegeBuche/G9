#define IR A0
#define ledC1 2
#define ledC2 3
#define ledC3 4
#define ledC4 5
#define ledC5 6
#define ledC6 7
int a1, a2, reading;
//setting hours, minutes, secound  and miliseconds to 0
int h=0;     
int m=0;     
int s=0;     
int ms=0;    
int sms=0;
int mms=0;
int hms=0;
int tms=0;

int h2=0;     
int m2=0;     
int s2=0;     
int ms2=0;    
int sms2=0;
int mms2=0;
int hms2=0;
int tms2=0;

void stopwatch()
{
  ms=ms+10;           
  delay(10); 
   
 if(ms==1000)           
  {
   
   ms=0; 
   s=s+1;
   sms=sms+1000; 
  }
  
  if(s==60)     //if state for counting up minutes
  { 
    s=0; 
    m=m+1;
    mms=mms+60000; 
  }

  if(m==60)      //if state for counting up hours
  {  
  m=00; 
  h=h+01;
  hms=hms+3600000;  
  } 
  tms=ms+sms+mms+hms;
}

void stopwatch2()
{
  ms2=ms2+10;           
  delay(10); 
   
 if(ms2==1000)           
  {
   
   ms2=0; 
   s2=s2+1;
   sms2=sms2+1000; 
  }
  
  if(s2==60)     //if state for counting up minutes
  { 
    s2=0; 
    m2=m2+1;
    mms2=mms2+60000; 
  }

  if(m2==60)      //if state for counting up hours
  {  
  m2=00; 
  h2=h2+01;
  hms2=hms2+3600000;  
  } 
  tms2=ms2+sms2+mms2+hms2;
}

void stopwatch_stop()
{   
   
 
}

void stopwatch_reset()
{
 ms=00;
 h=00;    //seting hours to 0
 m=00;    //seting minutes to 0
  s=00;    //seting seconds to 0
 return;  //exiting the program and returning  to the point where entered the program
}

void readSensor()
  {
    a1 = analogRead(A0);
    a2 = analogRead(A1);
    if (a1 < 400) a1 = 1; else a1 = 0;
    if (a2 < 400) a2 = 1; else a2 = 0;
    Serial.print(a1);
    Serial.print("\t");
    Serial.print(a2);
    Serial.print("\t");
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
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

  
} 
void loop() 
{ 
  
  
  readSensor();

  if (a1 = 1)
  {
    stopwatch();
  }

  

 

  if (tms > 5000)
  {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
  }

  if (tms2 > 5000)
  {
    digitalWrite(5, LOW);
    digitalWrite(7, HIGH);
  }


}
  

