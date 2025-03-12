#define IR A0
#define ledC1 2
#define ledC2 3
#define ledC3 4
#define ledC4 5
#define ledC5 6
#define ledC6 7
int a1, a2, b1, b2, c1, c2, d1, d2, reading;
int p=0;
int p1=0;
int pt1=0;
int ps1=0;
int p2=0;
int pt2=0;
int ps2=0;
int p3=0;
int pt3=0;
int ps3=0;
int p4=0;
int pt4=0;
int ps4=0;
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

int h3=0;     
int m3=0;     
int s3=0;     
int ms3=0;    
int sms3=0;
int mms3=0;
int hms3=0;
int tms3=0;

int h4=0;     
int m4=0;     
int s4=0;     
int ms4=0;    
int sms4=0;
int mms4=0;
int hms4=0;
int tms4=0;

int dh=0;     
int dm=0;     
int ds=0;     
int dms=0;    
int dsms=0;
int dmms=0;
int dhms=0;
int dtms=0;

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
  m=0; 
  h=h+1;
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
  m2=0; 
  h2=h2+1;
  hms2=hms2+3600000;  
  } 
  tms2=ms2+sms2+mms2+hms2;
}

void stopwatch3()
{
  ms3=ms3+10;           
  delay(10); 
   
 if(ms3==1000)           
  {
   
   ms3=0; 
   s3=s3+1;
   sms3=sms3+1000; 
  }
  
  if(s3==60)     //if state for counting up minutes
  { 
    s3=0; 
    m3=m3+1;
    mms3=mms3+60000; 
  }

  if(m3==60)      //if state for counting up hours
  {  
  m3=0; 
  h3=h3+1;
  hms3=hms3+3600000;  
  } 
  tms3=ms3+sms3+mms3+hms3;
} 
   
void stopwatch4()
{
  ms4=ms4+10;           
  delay(10); 
   
 if(ms4==1000)           
  {
   
   ms4=0; 
   s4=s4+1;
   sms4=sms4+1000; 
  }
  
  if(s4==60)     //if state for counting up minutes
  { 
    s4=0; 
    m4=m4+1;
    mms4=mms4+60000; 
  }

  if(m4==60)      //if state for counting up hours
  {  
  m4=0; 
  h4=h4+1;
  hms4=hms4+3600000;  
  } 
  tms4=ms4+sms4+mms4+hms4;
}

void dstopwatch()
{
  dms=dms+10;           
  delay(10); 
   
 if(dms==1000)           
  {
   
   dms=0; 
   ds=ds+1;
   dsms=dsms+1000; 
  }
  
  if(ds==60)     //if state for counting up minutes
  { 
    ds=0; 
    dm=dm+1;
    dmms=dmms+60000; 
  }

  if(dm==60)      //if state for counting up hours
  {  
  dm=0; 
  dh=dh+1;
  dhms=dhms+3600000;  
  } 
  dtms=dms+dsms+dmms+dhms;
}

void sreset()
{
  ms=0;
  h=0;    
  m=0;    
  s=0;
  sms=0;
  mms=0;
  hms=0;
  tms=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void sreset2()
{
  ms2=0;
  h2=0;    
  m2=0;    
  s2=0;
  sms2=0;
  mms2=0;
  hms2=0;
  tms2=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void sreset3()
{
  ms3=0;
  h3=0;    
  m3=0;    
  s3=0;
  sms3=0;
  mms3=0;
  hms3=0;
  tms3=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void sreset4()
{
  ms4=0;
  h4=0;    
  m4=0;    
  s4=0;
  sms4=0;
  mms4=0;
  hms4=0;
  tms4=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void dreset()
{
  dms=0;
  dh=0;    
  dm=0;    
  ds=0;
  dsms=0;
  dmms=0;
  dhms=0;
  dtms=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void readSensor()
  {
    
  a1 = analogRead(A7);
  a2 = analogRead(A6);
  b1 = analogRead(A4);
  b2 = analogRead(A5);
  c1 = analogRead(A1);
  c2 = analogRead(A0);
  d1 = analogRead(A3);
  d2 = analogRead(A2);

  if (a1 < 400) a1 = 1; else a1 = 0; if (a2 < 400) a2 = 1; else a2 = 0;
if (b1 < 400) b1 = 1; else b1 = 0; if (b2 < 400) b2 = 1; else b2 = 0;
if (c1 < 400) c1 = 1; else c1 = 0; if (c2 < 400) c2 = 1; else c2 = 0;
if (d1 < 400) d1 = 1; else d1 = 0; if (d2 < 400) d2 = 1; else d2 = 0;

Serial.print(a1);
Serial.print("\t");
Serial.print(a2);
Serial.print("\t");
Serial.print(b1);
Serial.print("\t");
Serial.print(b2);
Serial.print("\t");
Serial.print(c1);
Serial.print("\t");
Serial.print(c2);
Serial.print("\t");
Serial.print(d1);
Serial.print("\t");
Serial.print(d2);
Serial.println("\t");

  }

void a1compare()
{
  
      if (a1 == 1 && b1 == 1)
      {
        stopwatch2();
      }
      else if (a1 == 0 && b1 == 0)
        {
          sreset2();
        }
      if (a1 == 1 && c1 == 1)
      {
        stopwatch3();
      }
      else if (a1 == 0 && c1 == 0)
        {
          sreset3();
        }
      if (a1 == 1 && d1 == 1)
      {
        stopwatch4();
      }
      else if (a1 == 0 && d1 == 0)
        {
          sreset4();
        }
      if (tms > tms2 || tms > tms3 || tms > tms4)
      {
        pt1=1;
      }
    
}

void a2compare()
{
  
      if (b1 == 1 && a1 == 1)
      {
        stopwatch();
      }
      else if (b1 == 0 && a1 == 0)
        {
          sreset();
        }
      else if (b1 == 1 && c1 == 1)
      {
        stopwatch3();
      }
      else if (b1 == 0 && c1 == 0)
        {
          sreset3();
        }
      else if (b1 == 1 && d1 == 1)
      {
        stopwatch4();
      }
      else if (b1 == 0 && d1 == 0)
        {
          sreset4();
        }
      if (tms2 > tms || tms2 > tms3 || tms2 > tms4)
      {
        pt2=1;
      }
    
}

void a3compare()
{
  
      if (c1 == 1 && a1 == 1)
      {
        stopwatch();
      }
      else if (c1 == 0 && a1 == 0)
        {
          sreset();
        }
      else if (c1 == 1 && b1 == 1)
      {
        stopwatch2();
      }
      else if (c1 == 0 && b1 == 0)
        {
          sreset2();
        }
      else if (c1 == 1 && d1 == 1)
      {
        stopwatch4();
      }
      else if (c1 == 0 && d1 == 0)
        {
          sreset4();
        }
      if (tms3 > tms || tms3 > tms2 || tms3 > tms4)
      {
        pt3=1;
      }
    
}

void a4compare()
{
  
      if (d1 == 1 && a1 == 1)
      {
        stopwatch();
      }
      else if (d1 == 0 && a1 == 0)
        {
          sreset();
        }
      else if (d1 == 1 && b1 == 1)
      {
        stopwatch2();
      }
      else if (d1 == 0 && b1 == 0)
        {
          sreset2();
        }
      else if (d1 == 1 && c1 == 1)
      {
        stopwatch3();
      }
      else if (d1 == 0 && c1 == 0)
      {
        sreset3();
      }  
      if (tms4 > tms || tms4 > tms2 || tms4 > tms3)
      {
        pt4=1;
      }
      
    
}

void compare()
  {
    dstopwatch();
    if (dtms == 5000)
    {
      if (a1 == 1)
      {
        stopwatch();
        a1compare();
      
      }
      else 
      {
        sreset();
      }
      if (b1 == 1)
      {
        stopwatch2();
        a2compare();
      
      }
      else 
      {
        sreset2();
      }
      if (c1 == 1)
      {
        stopwatch3();
        a3compare();
      
      }
      else 
      {
        sreset3();
      }
      if (d1 == 1)
      {
        stopwatch4();
        a4compare();
     
      }
      else 
      {
        sreset4();
      }
      p1=pt1+ps1;
      p2=pt2+ps2;
      p3=pt3+ps3;
      p4=pt4+ps4;
      if (p1 >= 2)
      {
        p=1;
      }
      if (p2 == 2)
      {
        p=2;
      }
      if (p3 == 2)
      {
        p=3;
      }
      if (p4 == 2)
      {
        p=4;
      }
      dreset();
    }
  }

void scompare()
{
  if (tms == 5000)
  {
   if (a2 == 1)
   {
    ps1 = 1;
   }
  }
  else if (tms2 == 5000)
  {
   if (b2 == 1)
   {
    ps2 = 1;
   }
  }
  else if (tms3 == 5000)
  {
   if (c2 == 1)
   {
    ps3 = 1;
   }
  }
  else if (tms4 == 5000)
  {
   if (d2 == 1)
   {
    ps4 = 1;
   }
  }
}

void preset()
{
 p1=0;
 pt1=0;
 ps1=0;
 p2=0;
 pt2=0;
 ps2=0;
 p3=0;
 pt3=0;
 ps3=0;
 p4=0;
 pt4=0;
ps4=0;
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
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // Set all output to LOW in order to turn all LEDs off
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
} 
void loop() 
{ 

  readSensor();
  compare();

  switch (p) 
  {
  case 1:
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    break;
  case 2:
    digitalWrite(5, LOW);
    digitalWrite(7, HIGH);
    break;
  case 3:
    digitalWrite(8, LOW);
    digitalWrite(10, HIGH);
    break;
  case 4:
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
    break;
  default:
    // statements
    break;
  }
  preset();
}
  