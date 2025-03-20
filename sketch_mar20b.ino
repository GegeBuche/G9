#include <ArduinoQueue.h>

struct trafficLight {
  int frontSensor;                // input pin of front sensor
  int backSensor;                 // input pin of back sensor
  int frontValue;                 // value of front sensor
  int backValue;                  // value of back sensor
  int redPin;                     // output pin of red LED
  int yellowPin;                  // output pin of yellow LED
  int greenPin;                   // output pin of green LED
  int redValue;                   // value of red LED
  int yellowValue;                // value of yellow LED
  int greenValue;                 // value of green LED
  bool isFrontTrig;               // true if front sensor is triggered
  bool isBackTrig;                // true if back sensor is triggered
  unsigned long backSensorStart;  // start time when back sensor is triggered
};

ArduinoQueue<int> prioritySensor(8);  // holds the sequence of lane as per triggered sensor
ArduinoQueue<int> temp(8);            // temporary queue for congested lanes
trafficLight lane[4];                 // traffic light object

const int timeYellowToRed = 1000;
const int timeGreenToYellow = 2000;
const int timeNormalChange = 15000; 
const int timeCongested = 5000;

int openLane = 1;                     // holds which lane is currently green
int nextLane = 0;                     // holds which lane is next to be green

unsigned long curTime = 0;            // current time
unsigned long beginTime = 0;          // start time of a new sequence.
                                      // resets when a new lane turns green
unsigned long yrbeginTime = 0;
unsigned long gybeginTime = 0;

bool gy = false;
bool yr = false;

void setLaneToRed(int laneNo) {             // from yellow to red
// set values of LEDs
  lane[laneNo].redValue = HIGH;
  lane[laneNo].yellowValue = LOW;
  lane[laneNo].greenValue = LOW;
// send values to Arduino
  digitalWrite(lane[laneNo].redPin, lane[laneNo].redValue);
  digitalWrite(lane[laneNo].yellowPin, lane[laneNo].yellowValue);
  digitalWrite(lane[laneNo].greenPin, lane[laneNo].greenValue);
// set other properties
  //lane[laneNo].isFrontTrig = false;
  //lane[laneNo].isBackTrig = false;
  //lane[laneNo].backSensorStart = 0;
}

void setLaneToGreen(int laneNo) {           // from red to green
// set values of LEDs
  lane[laneNo].redValue = LOW;
  lane[laneNo].yellowValue = LOW;
  lane[laneNo].greenValue = HIGH;
// send values to Arduino
  digitalWrite(lane[laneNo].redPin, lane[laneNo].redValue);
  digitalWrite(lane[laneNo].yellowPin, lane[laneNo].yellowValue);
  digitalWrite(lane[laneNo].greenPin, lane[laneNo].greenValue);
// set other properties
  //lane[laneNo].isFrontTrig = true;
  //lane[laneNo].isBackTrig = false;
  //lane[laneNo].backSensorStart = 0;
}

void setLaneToYellow(int laneNo) {            // from green to yellow
// set values of LEDs
  lane[laneNo].redValue = LOW;
  lane[laneNo].yellowValue = HIGH;
  lane[laneNo].greenValue = LOW;
// send values to Arduino
  digitalWrite(lane[laneNo].redPin, lane[laneNo].redValue);
  digitalWrite(lane[laneNo].yellowPin, lane[laneNo].yellowValue);
  digitalWrite(lane[laneNo].greenPin, lane[laneNo].greenValue);
// set other properties
  //lane[laneNo].isFrontTrig = false;
  //lane[laneNo].isBackTrig = false;
  //lane[laneNo].backSensorStart = 0;
}

void setLane(int laneNo, int pinFS, int pinBS, int pinR, int pinY, int pinG, int valR, int valY, int valG, bool fTrig, bool bTrig, long unsigned timeBS) {
// set pin numbers
  lane[laneNo].frontSensor = pinFS;
  lane[laneNo].backSensor = pinBS;
  lane[laneNo].redPin = pinR;
  lane[laneNo].yellowPin = pinY;
  lane[laneNo].greenPin = pinG;
// set mode of LED pins to output
  pinMode(lane[laneNo].redPin, OUTPUT);
  pinMode(lane[laneNo].yellowPin, OUTPUT);
  pinMode(lane[laneNo].greenPin, OUTPUT);
// set values of LEDs
  lane[laneNo].redValue = valR;
  lane[laneNo].yellowValue = valY;
  lane[laneNo].greenValue = valG;
// send values to Arduino
  digitalWrite(lane[laneNo].redPin, lane[laneNo].redValue);
  digitalWrite(lane[laneNo].yellowPin, lane[laneNo].yellowValue);
  digitalWrite(lane[laneNo].greenPin, lane[laneNo].greenValue);
// set other properties
  lane[laneNo].isFrontTrig = fTrig;
  lane[laneNo].isBackTrig = bTrig;
  lane[laneNo].backSensorStart = timeBS;
}

bool check15seconds() {return (curTime - beginTime >= timeNormalChange) ? true : false;}

bool check2seconds() {return (curTime - gybeginTime >= timeGreenToYellow) ? true : false;}

bool check3seconds() {return (curTime - yrbeginTime >= timeYellowToRed) ? true : false;}

bool check5seconds(long unsigned backSensorBeginTime) {return (curTime - backSensorBeginTime >= timeCongested) ? true : false;}

void readFrontSensor() {
  lane[0].frontValue = analogRead(A4);
  lane[1].frontValue = analogRead(A5);
  lane[2].frontValue = analogRead(A6);
  lane[3].frontValue = analogRead(A7);
  if (lane[0].frontValue < 400 && !lane[0].isFrontTrig) {prioritySensor.enqueue(1);lane[0].isFrontTrig=true;}
  if (lane[1].frontValue < 400 && !lane[1].isFrontTrig) {prioritySensor.enqueue(2);lane[1].isFrontTrig=true;}
  if (lane[2].frontValue < 400 && !lane[2].isFrontTrig) {prioritySensor.enqueue(3);lane[2].isFrontTrig=true;}
  if (lane[3].frontValue < 400 && !lane[3].isFrontTrig) {prioritySensor.enqueue(4);lane[3].isFrontTrig=true;}
  if (lane[0].frontValue >= 400) {lane[0].isFrontTrig=false;}
  if (lane[1].frontValue >= 400) {lane[1].isFrontTrig=false;}
  if (lane[2].frontValue >= 400) {lane[2].isFrontTrig=false;}
  if (lane[3].frontValue >= 400) {lane[3].isFrontTrig=false;}
}

void readBackSensor() {
  lane[0].backValue = analogRead(A0);
  lane[1].backValue = analogRead(A1);
  lane[2].backValue = analogRead(A2);
  lane[3].backValue = analogRead(A3);

  // back sensors can only be triggered if the front sensors are also triggered.
  if (lane[0].backValue < 400 && !lane[0].isBackTrig && lane[0].isFrontTrig) {lane[0].isBackTrig=true;lane[0].backSensorStart=millis();}
  if (lane[1].backValue < 400 && !lane[1].isBackTrig && lane[1].isFrontTrig) {lane[1].isBackTrig=true;lane[1].backSensorStart=millis();}
  if (lane[2].backValue < 400 && !lane[2].isBackTrig && lane[2].isFrontTrig) {lane[2].isBackTrig=true;lane[2].backSensorStart=millis();}
  if (lane[3].backValue < 400 && !lane[3].isBackTrig && lane[3].isFrontTrig) {lane[3].isBackTrig=true;lane[3].backSensorStart=millis();}
  if (lane[0].backValue >= 400) {lane[0].isBackTrig=false;}
  if (lane[1].backValue >= 400) {lane[1].isBackTrig=false;}
  if (lane[2].backValue >= 400) {lane[2].isBackTrig=false;}
  if (lane[3].backValue >= 400) {lane[3].isBackTrig=false;}
}

void setup() {
  Serial.begin(9600);
  // set lanes
  setLane(0, A4, A0, 2, 3, 4, HIGH, LOW, LOW, false, false, 0);
  setLane(1, A5, A1, 5, 6, 7, HIGH, LOW, LOW, false, false, 0);
  setLane(2, A6, A2, 8, 9, 10, HIGH, LOW, LOW, false, false, 0);
  setLane(3, A7, A3, 11, 12, 13, HIGH, LOW, LOW, false, false, 0); 

  beginTime = millis();            // start time of a sequence
  setLaneToGreen(openLane-1);      // make lane 1 open
}

void loop() {
// get current time
  curTime = millis();

  // 1. check if there is a triggered front sensor, put the sensor in priority list (prioritySensor).
  //.   reset sensor.
  readFrontSensor();
  for (int i=1; i<=4; i++) {
    Serial.print("L");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(lane[i-1].isFrontTrig);
    Serial.print("-");
    Serial.print(lane[i-1].isBackTrig);
    Serial.print(" [");
    Serial.print(lane[i-1].frontValue);
    Serial.print("][");
    Serial.print(lane[i-1].backValue);
    Serial.print("]");
    Serial.print("\t"); 
  }
  Serial.print(prioritySensor.getHead());
  Serial.print(openLane);
  Serial.println(""); 
  
  // 2. check if there is a queued lane.
  //.   if there is, check if open lane sensor is 0.
  //.   if zero, change LED of priority lane.
  //    remove lane from priority list, reset beginTime.
  if (gy)
  {
    if (check2seconds())
    {
      setLaneToYellow(openLane-1);  
      yrbeginTime = millis();        // change open lane from Green to Yellow;
      yr = true;
      gy = false;
    }
  }
  else if (yr)
  {
    if (check3seconds())
    {
      setLaneToRed(openLane-1);             // change open lane from Yellow to Red;
      setLaneToGreen(nextLane-1);           // change next lane to Green
      
      openLane = nextLane;
      beginTime = millis();                 // a new lane turned green
      yr = false;
    }
  }
// 3. If there are no changes in LED, force change after 15 seconds.  
  else if (check15seconds()) {
    if (prioritySensor.isEmpty()) {
      nextLane = (openLane % 4) + 1;
    }
    else {
      nextLane = prioritySensor.dequeue();
    }
    Serial.print("AUTOCHANGING OPEN LANE >> ");
    Serial.println(nextLane);
    beginTime = millis();
    gybeginTime = millis();
    gy = true;
  }
  else if (lane[openLane-1].isFrontTrig) {

  }
  else
  {
    if (!prioritySensor.isEmpty()) {
      Serial.print("QUEUE IS NOT EMPTY. ");
      Serial.println(prioritySensor.getHead());
      if (prioritySensor.getHead() != openLane) {
        Serial.print("HEAD >> ");
        Serial.println(prioritySensor.getHead());
        //if (lane[openLane-1].isFrontTrig) {
          nextLane = prioritySensor.dequeue();        
          Serial.print("DEQUEUEING >> ");
          Serial.println(nextLane);
          gybeginTime = millis();
          gy = true;
        //} 
      }
      else
      {
        prioritySensor.dequeue();
      }
    }
  }

  // 4. check if a back sensor is triggered, save the time (backSensorStart).
  readBackSensor();

  // 5. If there is a back sensor triggered for more than 5 seconds, move to first priority.
  //.   Adjust other lanes in the priority list.
  for (int i=0; i<4; i++) {
    if (lane[i].isBackTrig && check5seconds(lane[i].backSensorStart)) {
      Serial.print("PRIORITIZING CONGESTED LANE. ");
      Serial.println(i+1);
      for (int j = 0; j < prioritySensor.itemCount(); j++) {     
        temp.enqueue(prioritySensor.dequeue());
      }
      prioritySensor.enqueue(i+1);
      for (int j = 0; j < temp.itemCount(); j++) {
        if (temp.getHead() != j+1) {prioritySensor.enqueue(temp.dequeue());}
        else {temp.dequeue();j++;}
      }
      
    }
  }
}

