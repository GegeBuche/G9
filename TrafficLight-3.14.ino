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
int l=0;
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

int gyh=0;     
int gym=0;     
int gys=0;     
int gyms=0;    
int gysms=0;
int gymms=0;
int gyhms=0;
int gytms=0;

int ryh=0;     
int rym=0;     
int rys=0;     
int ryms=0;    
int rysms=0;
int rymms=0;
int ryhms=0;
int rytms=0;

int rgh=0;     
int rgm=0;     
int rgs=0;     
int rgms=0;    
int rgsms=0;
int rgmms=0;
int rghms=0;
int rgtms=0;

int gyh2=0;     
int gym2=0;     
int gys2=0;     
int gyms2=0;    
int gysms2=0;
int gymms2=0;
int gyhms2=0;
int gytms2=0;

int ryh2=0;     
int rym2=0;     
int rys2=0;     
int ryms2=0;    
int rysms2=0;
int rymms2=0;
int ryhms2=0;
int rytms2=0;

int rgh2=0;
int rgm2=0;     
int rgs2=0;     
int rgms2=0;    
int rgsms2=0;
int rgmms2=0;
int rghms2=0;
int rgtms2=0;

int gyh3=0;     
int gym3=0;     
int gys3=0;     
int gyms3=0;    
int gysms3=0;
int gymms3=0;
int gyhms3=0;
int gytms3=0;

int ryh3=0;     
int rym3=0;     
int rys3=0;     
int ryms3=0;    
int rysms3=0;
int rymms3=0;
int ryhms3=0;
int rytms3=0;

int rgh3=0;     
int rgm3=0;     
int rgs3=0;     
int rgms3=0;    
int rgsms3=0;
int rgmms3=0;
int rghms3=0;
int rgtms3=0;

int gyh4=0;     
int gym4=0;     
int gys4=0;     
int gyms4=0;    
int gysms4=0;
int gymms4=0;
int gyhms4=0;
int gytms4=0;

int ryh4=0;     
int rym4=0;     
int rys4=0;     
int ryms4=0;    
int rysms4=0;
int rymms4=0;
int ryhms4=0;
int rytms4=0;

int rgh4=0;     
int rgm4=0;     
int rgs4=0;     
int rgms4=0;    
int rgsms4=0;
int rgmms4=0;
int rghms4=0;
int rgtms4=0;

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

void gystopwatch()
{
  gyms=gyms+10;           
  delay(10); 
   
 if(gyms==1000)           
  {
   
   gyms=0; 
   gys=gys+1;
   gysms=gysms+1000; 
  }
  
  if(gys==60)     //if state for counting up minutes
  { 
    gys=0; 
    gym=gym+1;
    gymms=gymms+60000; 
  }

  if(gym==60)      //if state for counting up hours
  {  
    gym=0; 
    gyh=gyh+1;
    gyhms=gyhms+3600000;  
  } 
  gytms=gyms+gysms+gymms+gyhms;
}

void rystopwatch()
{
  ryms=ryms+10;           
  delay(10); 
   
 if(ryms==1000)           
  {
   
   ryms=0; 
   rys=rys+1;
   rysms=rysms+1000; 
  }
  
  if(rys==60)     //if state for counting up minutes
  { 
    rys=0; 
    rym=rym+1;
    rymms=rymms+60000; 
  }

  if(rym==60)      //if state for counting up hours
  {  
  rym=0; 
  ryh=ryh+1;
  ryhms=ryhms+3600000;  
  } 
  rytms=ryms+rysms+rymms+ryhms;
}

void rgstopwatch()
{
  rgms=rgms+10;           
  delay(10); 
   
 if(rgms==1000)           
  {
   
   rgms=0; 
   rgs=rgs+1;
   rgsms=rgsms+1000; 
  }
  
  if(rgs==60)     //if state for counting up minutes
  { 
    rgs=0; 
    rgm=rgm+1;
    rgmms=rgmms+60000; 
  }

  if(rgm==60)      //if state for counting up hours
  {  
    rgm=0; 
    rgh=rgh+1;
    rghms=rghms+3600000;  
  } 
  rgtms=rgms+rgsms+rgmms+rghms;
}

void gystopwatch2()
{
  gyms2=gyms2+10;           
  delay(10); 
   
 if(gyms2==1000)           
  {
   
   gyms2=0; 
   gys2=gys2+1;
   gysms2=gysms2+1000; 
  }
  
  if(gys2==60)     //if state for counting up minutes
  { 
    gys2=0; 
    gym2=gym2+1;
    gymms2=gymms2+60000; 
  }

  if(gym2==60)      //if state for counting up hours
  {  
  gym2=0; 
  gyh2=gyh2+1;
  gyhms2=gyhms2+3600000;  
  } 
  gytms2=gyms2+gysms2+gymms2+gyhms2;
}

void rystopwatch2()
{
  ryms2=ryms2+10;           
  delay(10); 
   
 if(ryms2==1000)           
  {
   
   ryms2=0; 
   rys2=rys2+1;
   rysms2=rysms2+1000; 
  }
  
  if(rys2==60)     //if state for counting up minutes
  { 
    rys2=0; 
    rym2=rym2+1;
    rymms2=rymms2+60000; 
  }

  if(rym2==60)      //if state for counting up hours
  {  
  rym2=0; 
  ryh2=ryh2+1;
  ryhms2=ryhms2+3600000;  
  } 
  rytms2=ryms2+rysms2+rymms2+ryhms2;
}

void rgstopwatch2()
{
  rgms2=rgms2+10;           
  delay(10); 
   
 if(rgms2==1000)           
  {
   
   rgms2=0; 
   rgs2=rgs2+1;
   rgsms2=rgsms2+1000; 
  }
  
  if(rgs2==60)     //if state for counting up minutes
  { 
    rgs2=0; 
    rgm2=rgm2+1;
    rgmms2=rgmms2+60000; 
  }

  if(rgm2==60)      //if state for counting up hours
  {  
    rgm2=0; 
    rgh2=rgh2+1;
    rghms2=rghms2+3600000;  
  } 
  rgtms2=rgms2+rgsms2+rgmms2+rghms2;
}

void gystopwatch3()
{
  gyms3=gyms3+10;           
  delay(10); 
   
 if(gyms3==1000)           
  {
   
   gyms3=0; 
   gys3=gys3+1;
   gysms3=gysms3+1000; 
  }
  
  if(gys3=60)     //if state for counting up minutes
  { 
    gys3=0; 
    gym3=gym3+1;
    gymms3=gymms3+60000; 
  }

  if(gym3==60)      //if state for counting up hours
  {  
  gym3=0; 
  gyh3=gyh3+1;
  gyhms3=gyhms3+3600000;  
  } 
  gytms3=gyms3+gysms3+gymms3+gyhms3;
}

void rystopwatch3()
{
  ryms3=ryms3+10;           
  delay(10); 
   
 if(ryms3==1000)           
  {
   
   ryms3=0; 
   rys3=rys3+1;
   rysms3=rysms3+1000; 
  }
  
  if(rys3==60)     //if state for counting up minutes
  { 
    rys3=0; 
    rym3=rym3+1;
    rymms3=rymms3+60000; 
  }

  if(rym3==60)      //if state for counting up hours
  {  
  rym3=0; 
  ryh3=ryh3+1;
  ryhms3=ryhms3+3600000;  
  } 
  rytms3=ryms3+rysms3+rymms3+ryhms3;
}

void rgstopwatch3()
{
  rgms3=rgms3+10;           
  delay(10); 
   
 if(rgms3==1000)           
  {
   
   rgms3=0; 
   rgs3=rgs3+1;
   rgsms3=rgsms3+1000; 
  }
  
  if(rgs3==60)     //if state for counting up minutes
  { 
    rgs3=0; 
    rgm3=rgm3+1;
    rgmms3=rgmms3+60000; 
  }

  if(rgm3==60)      //if state for counting up hours
  {  
    rgm3=0; 
    rgh3=rgh3+1;
    rghms3=rghms3+3600000;  
  } 
  rgtms3=rgms3+rgsms3+rgmms3+rghms3;
}

void gystopwatch4()
{
  gyms4=gyms4+10;           
  delay(10); 
   
 if(gyms4==1000)           
  {
   
   gyms4=0; 
   gys4=gys4+1;
   gysms4=gysms4+1000; 
  }
  
  if(gys4==60)     //if state for counting up minutes
  { 
    gys4=0; 
    gym4=gym4+1;
    gymms4=gymms4+60000; 
  }

  if(gym4==60)      //if state for counting up hours
  {  
  gym4=0; 
  gyh4=gyh4+1;
  gyhms4=gyhms4+3600000;  
  } 
  gytms4=gyms4+gysms4+gymms4+gyhms4;
}

void rystopwatch4()
{
  ryms4=ryms4+10;           
  delay(10); 
   
 if(ryms4==1000)           
  {
   
   ryms4=0; 
   rys4=rys4+1;
   rysms4=rysms4+1000; 
  }
  
  if(rys4==60)     //if state for counting up minutes
  { 
    rys4=0; 
    rym4=rym4+1;
    rymms4=rymms4+60000; 
  }

  if(rym4==60)      //if state for counting up hours
  {  
  rym4=0; 
  ryh4=ryh4+1;
  ryhms4=ryhms4+3600000;  
  } 
  rytms4=ryms4+rysms4+rymms4+ryhms4;
}

void rgstopwatch4()
{
  rgms4=rgms4+10;           
  delay(10); 
   
 if(rgms4==1000)           
  {
   
   rgms4=0; 
   rgs4=rgs4+1;
   rgsms4=rgsms4+1000; 
  }
  
  if(rgs4==60)     //if state for counting up minutes
  { 
    rgs4=0; 
    rgm4=rgm4+1;
    rgmms4=rgmms4+60000; 
  }

  if(rgm4==60)      //if state for counting up hours
  {  
  rgm4=0; 
  rgh4=rgh4+1;
  rghms4=rghms4+3600000;  
  } 
  rgtms4=rgms4+rgsms4+rgmms4+rghms4;
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

void gysreset()
{
  gyms=0;
  gyh=0;    
  gym=0;    
  gys=0;
  gysms=0;
  gymms=0;
  gyhms=0;
  gytms=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void rysreset()
{
  ryms=0;
  ryh=0;    
  rym=0;    
  rys=0;
  rysms=0;
  rymms=0;
  ryhms=0;
  rytms=0;    
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

void gysreset2()
{
  gyms2=0;
  gyh2=0;    
  gym2=0;    
  gys2=0;
  gysms2=0;
  gymms2=0;
  gyhms2=0;
  gytms2=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void rysreset2()
{
  ryms2=0;
  ryh2=0;    
  rym2=0;    
  rys2=0;
  rysms2=0;
  rymms2=0;
  ryhms2=0;
  rytms2=0;    
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

void gysreset3()
{
  gyms3=0;
  gyh3=0;    
  gym3=0;    
  gys3=0;
  gysms3=0;
  gymms3=0;
  gyhms3=0;
  gytms3=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void rysreset3()
{
  ryms3=0;
  ryh3=0;    
  rym3=0;    
  rys3=0;
  rysms3=0;
  rymms3=0;
  ryhms3=0;
  rytms3=0;    
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

void gysreset4()
{
  gyms4=0;
  gyh4=0;    
  gym4=0;    
  gys4=0;
  gysms4=0;
  gymms4=0;
  gyhms4=0;
  gytms4=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void rysreset4()
{
  ryms4=0;
  ryh4=0;    
  rym4=0;    
  rys4=0;
  rysms4=0;
  rymms4=0;
  ryhms4=0;
  rytms4=0;    
  return;  //exiting the program and returning  to the point where entered the program
}

void wswitch()
{
  switch (p)
  {
  case 1:
    if (7, HIGH)
    {
      gystopwatch2();
      if (gytms2 == 3000)
      {
        digitalWrite(7, LOW);
        digitalWrite(6, HIGH);
        gysreset2();
        rystopwatch2();
        if (rytms2 == 2000)
        {
          digitalWrite(6, LOW);
          digitalWrite(5, HIGH);
          digitalWrite(2, LOW);
          digitalWrite(4, HIGH);
          rysreset2();
        }
      }
    }
    if (10, HIGH)
    {
      gystopwatch3();
      if (gytms3 == 3000)
      {
        digitalWrite(10, LOW);
        digitalWrite(9, HIGH);
        gysreset3();
        rystopwatch3();
        if (rytms3 == 2000)
        {
          digitalWrite(9, LOW);
          digitalWrite(8, HIGH);
          digitalWrite(2, LOW);
          digitalWrite(4, HIGH);
          rysreset3();
        }
      }
    }
    if (13, HIGH)
    {
      gystopwatch4();
      if (gytms4 == 3000)
      {
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        gysreset4();
        rystopwatch4();
        if (rytms4 == 2000)
        {
          digitalWrite(12, LOW);
          digitalWrite(11, HIGH);
          digitalWrite(2, LOW);
          digitalWrite(4, HIGH);
          rysreset4();
        }
      }
    }
    break;
  case 2:
    digitalWrite(5, LOW);
    if (4, HIGH)
    {
      
      gystopwatch();
      if (gytms == 3000)
      {
        digitalWrite(4, LOW);
        digitalWrite(3, HIGH);
        gysreset();
        rystopwatch();
        if (rytms == 2000)
        {
          digitalWrite(3, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(7, HIGH);
          rysreset();
        }
      }
    }
    if (10, HIGH)
    {
      gystopwatch3();
      if (gytms3 == 3000)
      {
        digitalWrite(10, LOW);
        digitalWrite(9, HIGH);
        rystopwatch3();
        if (rytms3 == 2000)
        {
          digitalWrite(9, LOW);
          digitalWrite(8, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(7, HIGH);
          rysreset3();
        }
      }
    }
    if (13, HIGH)
    {
      gystopwatch4();
      if (gytms4 == 3000)
      {
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        gysreset4();
        rystopwatch4();
        if (rytms4 == 2000)
        {
          digitalWrite(12, LOW);
          digitalWrite(11, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(7, HIGH);
          rysreset4();
        }
      }
    }
    break;
  case 3:
    if (4, HIGH)
    {
      gystopwatch();
      if (gytms == 3000)
      {
        digitalWrite(4, LOW);
        digitalWrite(3, HIGH);
        gysreset();
        rystopwatch();
        if (rytms == 2000)
        {
          digitalWrite(3, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(10, HIGH);
          rysreset();
        }
      }
    }
    if (7, HIGH)
    {
      gystopwatch2();
      if (gytms2 == 3000)
      {
        digitalWrite(7, LOW);
        digitalWrite(6, HIGH);
        gysreset2();
        rystopwatch2();
        if (rytms2 == 2000)
        {
          digitalWrite(6, LOW);
          digitalWrite(5, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(10, HIGH);
          rysreset2();
        }
      }
    }
    if (13, HIGH)
    {
      gystopwatch4();
      if (gytms4 == 3000)
      {
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        gysreset4();
        rystopwatch4();
        if (rytms4 == 2000)
        {
          digitalWrite(12, LOW);
          digitalWrite(11, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(10, HIGH);
          rysreset4();
        }
      }
    }
    break;
  case 4:
    if (4, HIGH)
    {
      gystopwatch();
      if (gytms == 3000)
      {
        digitalWrite(4, LOW);
        digitalWrite(3, HIGH);
        gysreset();
        rystopwatch();
        if (rytms == 2000)
        {
          digitalWrite(3, LOW);
          digitalWrite(2, HIGH);
          digitalWrite(11, LOW);
          digitalWrite(13, HIGH);
          rysreset();
        }
      }
    }
    if (7, HIGH)
    {
      gystopwatch2();
      if (gytms2 == 3000)
      {
        digitalWrite(7, LOW);
        digitalWrite(6, HIGH);
        gysreset2();
        rystopwatch2();
        if (rytms2 == 2000)
        {
          digitalWrite(6, LOW);
          digitalWrite(5, HIGH);
          digitalWrite(11, LOW);
          digitalWrite(13, HIGH);
          rysreset2();
        }
      }
    }
    if (10, HIGH)
    {
      gystopwatch3();
      if (gytms3 == 3000)
      {
        digitalWrite(10, LOW);
        digitalWrite(9, HIGH);
        rystopwatch3();
        if (rytms3 == 2000)
        {
          digitalWrite(9, LOW);
          digitalWrite(8, HIGH);
          digitalWrite(11, LOW);
          digitalWrite(13, HIGH);
          rysreset3();
        }
      }
    }
    break;
  default:
    // statements
    break;
  }
}

void readSensor()
  {
    
  a1 = analogRead(A0);
  a2 = analogRead(A1);
  b1 = analogRead(A2);
  b2 = analogRead(A3);
  c1 = analogRead(A4);
  c2 = analogRead(A5);
  d1 = analogRead(A6);
  d2 = analogRead(A7);

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
      else if (b1 == 0)
        {
          sreset2();
        }
      if (a1 == 1 && c1 == 1)
      {
        stopwatch3();
      }
      else if (c1 == 0)
        {
          sreset3();
        }
      if (a1 == 1 && d1 == 1)
      {
        stopwatch4();
      }
      else if (d1 == 0)
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
      else if (a1 == 0)
        {
          sreset();
        }
      else if (b1 == 1 && c1 == 1)
      {
        stopwatch3();
      }
      else if (c1 == 0)
        {
          sreset3();
        }
      else if (b1 == 1 && d1 == 1)
      {
        stopwatch4();
      }
      else if (d1 == 0)
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
      else if (a1 == 0)
        {
          sreset();
        }
      else if (c1 == 1 && b1 == 1)
      {
        stopwatch2();
      }
      else if (b1 == 0)
        {
          sreset2();
        }
      else if (c1 == 1 && d1 == 1)
      {
        stopwatch4();
      }
      else if (d1 == 0)
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
      else if (a1 == 0)
        {
          sreset();
        }
      else if (d1 == 1 && b1 == 1)
      {
        stopwatch2();
      }
      else if (b1 == 0)
        {
          sreset2();
        }
      else if (d1 == 1 && c1 == 1)
      {
        stopwatch3();
      }
      else if (c1 == 0)
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
    switch (c)
    {
      case 1:
        if (a1 == 1)
        {
          stopwatch();
          a1compare();
        }
        else
        {
          sreset();
        }
        break;
      case 2:
        if (b1 == 1)
        {
          stopwatch2();
          a2compare();
        }
        else
        {
          sreset2();
        }
        break;
      case 3:
        if (c1 == 1)
        {
          stopwatch3();
          a3compare();
        }
        else
        {
          sreset3();
        }
        break;
      case 4:
        if (d1 == 1)
        {
          stopwatch4();
          a4compare();
        }
        else
        {
          sreset4();
        }
        break;
      default:

        break;
    }
    p1=pt1+ps1;
    p2=pt2+ps2;
    p3=pt3+ps3;
    p4=pt4+ps4;
    if (p1 == 1)
    {
      p=1;
    }
    if (p2 == 1)
    {
      p=2;
    }
    if (p3 == 1)
    {
      p=3;
    }
    if (p4 == 1)
    {
      p=4;
    }
  }

void preset()
{
 p=0;
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
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
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

  
  Serial.print("p=");
  Serial.println(p);
  while (4, HIGH)
  {
    l=1;
    readSensor();
    compare();
    Serial.print("p=");
    Serial.println(p);
    wswitch();
    digitalWrite(7, LOW);
    digitalWrite(10, LOW);
    digitalWrite(13, LOW);
    preset();
    if (l == 1)
    {
      p1=0;
      pt1=0;
      ps1=0;
    }
  }
  while (7, HIGH)
  {
    l=2;
    readSensor();
    compare();
    Serial.print("p=");
    Serial.println(p);
    wswitch();
    digitalWrite(4, LOW);
    digitalWrite(10, LOW);
    digitalWrite(13, LOW);
    preset();
    if (l == 2)
    {
      p2=0;
      pt2=0;
      ps2=0;
    }
  }
  while (10, HIGH)
  {
    l=3;
    readSensor();
    compare();
    Serial.print("p=");
    Serial.println(p);
    wswitch();
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(13, LOW);
    preset();
    if (l == 3)
    {
      p3=0;
      pt3=0;
      ps3=0;
    }
  }
  while (13, HIGH)
  {
    l=4;
    readSensor();
    compare();
    Serial.print("p=");
    Serial.println(p);
    wswitch();
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(10, LOW);
    preset();
    if (l == 4)
    {
      p4=0;
      pt4=0;
      ps4=0;
    }
  }
  
}
  
