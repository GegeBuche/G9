#include <ArduinoQueue.h>

struct trafficLight {
  int frontSensor;                // input pin of front sensor
  int backSensor;                 // input pin of back sensor
  int redPin;                     // output pin of red LED
  int yellowPin;                  // output pin of yellow LED
  int greenPin;                   // output pin of green LED
  int redValue;                   // value of red LED
  int yellowValue;                  // value of yellow LED
  int greenValue;                   // value of green LED
  bool frontTrig;                 // true if front sensor is triggered
  bool backTrig;                  // true if back sensor is triggered
  unsigned long backSensorTime;   // start time when back sensor is triggered
};

ArduinoQueue<int> prioritySensor(4);  // holds the sequence of lane as per triggered sensor
trafficLight lane[4];                 // traffic light object
const int timeYellowToRed = 3000;
const int timeGreenToYellow = 2000;
const int timeRedToGreen = 15000; 
const int timeToBeCongested = 5000;

int openLane = 1;                     // holds which lane is currently enabled
int nextLane = 0;

unsigned long curTime = 0;
unsigned long beginTime = 0;
unsigned long yrbeginTime = 0;
unsigned long gybeginTime = 0;

int a1, a2, b1, b2, c1, c2, d1, d2;

bool gy = false;
bool yr = false;

void setRedLane(int laneNo) {
  lane[laneNo].redValue = HIGH;
  digitalWrite(lane[laneNo].redPin, lane[laneNo].redValue);
  lane[laneNo].yellowValue = LOW;
  digitalWrite(lane[laneNo].yellowPin, lane[laneNo].yellowValue);
  lane[laneNo].greenValue = LOW;
  digitalWrite(lane[laneNo].greenPin, lane[laneNo].greenValue);
  lane[laneNo].frontTrig = false;
  lane[laneNo].backTrig = false;
  lane[laneNo].backSensorTime = 0;
}

void setGreenLane(int laneNo) {
  lane[laneNo].redValue = LOW;
  digitalWrite(lane[laneNo].redPin, lane[laneNo].redValue);
  lane[laneNo].yellowValue = LOW;
  digitalWrite(lane[laneNo].yellowPin, lane[laneNo].yellowValue);
  lane[laneNo].greenValue = HIGH;
  digitalWrite(lane[laneNo].greenPin, lane[laneNo].greenValue);
  lane[laneNo].frontTrig = false;
  lane[laneNo].backTrig = false;
  lane[laneNo].backSensorTime = 0;
}

void setYellowLane(int laneNo) {
  lane[laneNo].redValue = LOW;
  digitalWrite(lane[laneNo].redPin, lane[laneNo].redValue);
  lane[laneNo].yellowValue = HIGH;
  digitalWrite(lane[laneNo].yellowPin, lane[laneNo].yellowValue);
  lane[laneNo].greenValue = LOW;
  digitalWrite(lane[laneNo].greenPin, lane[laneNo].greenValue);
  lane[laneNo].frontTrig = false;
  lane[laneNo].backTrig = false;
  lane[laneNo].backSensorTime = 0;
}

void setLane(int laneNo, int pinFS, int pinBS, int pinR, int pinY, int pinG, int valR, int valY, int valG, bool fTrig, bool bTrig, long unsigned timeBS) {
  lane[laneNo].frontSensor = pinFS;
  lane[laneNo].backSensor = pinBS;
  lane[laneNo].redPin = pinR;
  pinMode(lane[laneNo].redPin, OUTPUT);
  lane[laneNo].yellowPin = pinY;
  pinMode(lane[laneNo].yellowPin, OUTPUT);
  lane[laneNo].greenPin = pinG;
  pinMode(lane[laneNo].greenPin, OUTPUT);
  lane[laneNo].redValue = valR;
  digitalWrite(lane[laneNo].redPin, lane[laneNo].redValue);
  lane[laneNo].yellowValue = valY;
  digitalWrite(lane[laneNo].yellowPin, lane[laneNo].yellowValue);
  lane[laneNo].greenValue = valG;
  digitalWrite(lane[laneNo].greenPin, lane[laneNo].greenValue);
  lane[laneNo].frontTrig = fTrig;
  lane[laneNo].backTrig = bTrig;
  lane[laneNo].backSensorTime = timeBS;
}

bool check15seconds() {
  return (curTime - beginTime >= 15000) ? true : false; 
}

bool check2seconds() {
  return (curTime - gybeginTime >= 2000) ? true : false; 
}

bool check3seconds() {
  return (curTime - yrbeginTime >= 3000) ? true : false; 
}

bool check5seconds(long unsigned backSensorBeginTime) {
  return (curTime - backSensorBeginTime >= 5000) ? true : false;
}

void readFrontSensor() {
  a1=analogRead(A0);
  b1=analogRead(A1);
  c1=analogRead(A2);
  d1=analogRead(A3);
  if (a1 < 400 && !lane[0].frontTrig) {prioritySensor.enqueue(1);lane[0].frontTrig=true;}
  if (b1 < 400 && !lane[1].frontTrig) {prioritySensor.enqueue(2);lane[1].frontTrig=true;}
  if (c1 < 400 && !lane[2].frontTrig) {prioritySensor.enqueue(3);lane[2].frontTrig=true;}
  if (d1 < 400 && !lane[3].frontTrig) {prioritySensor.enqueue(4);lane[3].frontTrig=true;}
  Serial.print(a1);
  Serial.print("\t");
  Serial.print(b1);
  Serial.print("\t");
  Serial.print(c1);
  Serial.print("\t");
  Serial.print(d1);
  Serial.println("\t");
}

void readBackSensor() {
  a2=analogRead(A4);
  b2=analogRead(A5);
  c2=analogRead(A6);
  d2=analogRead(A7);
  if (a2 < 400 && !lane[0].backTrig) {prioritySensor.enqueue(1);lane[0].backTrig=true;lane[0].backSensorTime=millis();}
  if (b2 < 400 && !lane[1].backTrig) {prioritySensor.enqueue(2);lane[1].backTrig=true;lane[1].backSensorTime=millis();}
  if (c2 < 400 && !lane[2].backTrig) {prioritySensor.enqueue(3);lane[2].backTrig=true;lane[2].backSensorTime=millis();}
  if (d2 < 400 && !lane[3].backTrig) {prioritySensor.enqueue(4);lane[3].backTrig=true;lane[3].backSensorTime=millis();}
  Serial.print(a2);
  Serial.print("\t");
  Serial.print(b2);
  Serial.print("\t");
  Serial.print(c2);
  Serial.print("\t");
  Serial.print(d2);
  Serial.println("\t");
}

void setup() {
  Serial.begin(9600);

  

  
  // set lanes
  setLane(0, A0, A4, 2, 3, 4, HIGH, LOW, LOW
  , false, false, 0);
  setLane(1, A1, A5, 5, 6, 7, HIGH, LOW, LOW, false, false, 0);
  setLane(2, A2, A6, 8, 9, 10, HIGH, LOW, LOW, false, false, 0);
  setLane(3, A3, A7, 11, 12, 13, HIGH, LOW, LOW, false, false, 0);

  beginTime = millis();
  setGreenLane(openLane);              // make lane 1 open
}

void loop() {
  // put your main code here, to run repeatedly:
  curTime = millis();

  // 1. check if there is a triggered front sensor, put the sensor in priority list (prioritySensor).
  //.   reset sensor.
  readFrontSensor();
  Serial.print("L1 Triggered: ");
  Serial.print(lane[0].frontTrig);
  Serial.print("\t");
  Serial.print("L2 Triggered: ");
  Serial.print(lane[1].frontTrig);
  Serial.print("\t");
  Serial.print("L3 Triggered: ");
  Serial.print(lane[2].frontTrig);
  Serial.print("\t");
  Serial.print("L4 Triggered: ");
  Serial.print(lane[3].frontTrig);
  Serial.println("\t");
  
  Serial.print("open lane: ");
  Serial.print(openLane);
  Serial.print("\t");
  Serial.print("next lane: ");
  Serial.print(nextLane);
  Serial.print("\t");
   // 2. check if there is a queued lane.
  //.   if there is, check if open lane sensor is 0.
  //.   if zero, change LED of priority lane.
  //    remove lane from priority list, reset beginTime.
  if (gy)
  {
    if (check2seconds())
    {
      setYellowLane(openLane-1);  
            yrbeginTime = millis();        // change open lane from Green to Yellow;
            yr = true;
            gy = false;
    }
  }
  else if (yr)
  {
    if (check3seconds())
            {
              setRedLane(openLane-1);             // change open lane from Yellow to Red;
              setGreenLane(nextLane-1);           // change next lane to Green
              lane[openLane-1].frontTrig = false;
              openLane = nextLane;
              beginTime = millis();
              yr = false;
            }
  }
  else
  {
    if (!prioritySensor.isEmpty()) {
      Serial.print("check>>");
      Serial.print(prioritySensor.getHead());
      Serial.print("\t");
      Serial.println();
      if (prioritySensor.getHead() != openLane) {
        nextLane = prioritySensor.dequeue();
        if (!lane[nextLane-1].frontTrig) {
          
          gybeginTime = millis();
          gy = true;
                    // new starting time
        } 
      }
    }
  }
  // 3. check if a back sensor is triggered, save time the sensor is triggered (backSensorTime).
 /* readBackSensor();

  // 4. If there is a back sensor triggered for more than 5 seconds, move to first priority.
  //.   Adjust other lanes in the priority list.
  ArduinoQueue<int> temp(4);
  if (lane[0].backTrig && check5seconds(lane[0].backSensorTime)) {
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    prioritySensor.enqueue(1);
    for (int i = 0, j = 1; i <= 3; i++) {
      if (temp.getHead() != 1) {
        prioritySensor.enqueue(temp.dequeue());
        j++;
      }
    }
    lane[0].backTrig = false;
  }
  if (lane[1].backTrig && check5seconds(lane[1].backSensorTime)) {
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    prioritySensor.enqueue(2);
    for (int i = 0, j = 1; i <= 3; i++) {
      if (temp.getHead() != 2) {
        prioritySensor.enqueue(temp.dequeue());
        j++;
      }
    }
    lane[1].backTrig = false;
  }
  if (lane[2].backTrig && check5seconds(lane[1].backSensorTime)) {
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    prioritySensor.enqueue(3);
    for (int i = 0, j = 1; i <= 3; i++) {
      if (temp.getHead() != 3) {
        prioritySensor.enqueue(temp.dequeue());
        j++;
      }
    }
    lane[2].backTrig = false;
  }
  if (lane[3].backTrig && check5seconds(lane[1].backSensorTime)) {
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    temp.enqueue(prioritySensor.dequeue());
    prioritySensor.enqueue(4);
    for (int i = 0, j = 1; i <= 3; i++) {
      if (temp.getHead() != 4) {
        prioritySensor.enqueue(temp.dequeue());
        j++;
      }
    }
    lane[3].backTrig = false;
  } */

  // 5. If there are no changes in LED, force change after 15 seconds.
  /*if ()
  {

  }
  else*/ if (check15seconds()) {
    int nextLane;
    if (prioritySensor.isEmpty()) {
      nextLane = (openLane % 4) + 1;
    }
    else {
      nextLane = prioritySensor.dequeue();
    }
    if (check2seconds())
    {
      setYellowLane(openLane-1);  
      yrbeginTime = millis();
      if (check3seconds())
        {
          setRedLane(openLane-1);             // change open lane from Yellow to Red;
          setGreenLane(nextLane-1);           // change next lane to Green
          lane[openLane-1].frontTrig = false;
          openLane = nextLane;
          beginTime = millis();
        }     
    }              // new starting time
  }
}
