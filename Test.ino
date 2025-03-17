#include <ArduinoQueue.h>

ArduinoQueue<int> prioritySensor(4);  // holds the sequence of lane as per triggered sensor
unsigned long backSensorTime[4];  // time elapsed the back sensor is triggered
int lane[4];            // holds pin number of sensors of four lanes
bool trigFront[4];      // true if front sensor is triggered
bool trigBack[4];       // true if back sensor is triggered

int a1, a2, b1, b2, c1, c2, d1, d2;

const int timeYellowToRed = 3000;
const int timeGreenToYellow = 2000;
const int timeRedToGreen = 15000;
const int timeToBeCongested = 5000;  // time

int openLane = 0;  // holds which lane is currently enabled
//int nextLaneNotCongested = 0;  // holds which lane would open next on light traffic.
int nextLaneCongested = 0;  // holds which lane would open next on heavy traffic.
bool trigSensor = false;    // tells if any of the sensors is triggered



unsigned long curTime = 0;
unsigned long beginTime = 0;

void readSensor() {

  a1 = analogRead(A0);
  a2 = analogRead(A1);
  b1 = analogRead(A2);
  b2 = analogRead(A3);
  c1 = analogRead(A4);
  c2 = analogRead(A5);
  d1 = analogRead(A6);
  d2 = analogRead(A7);

  if (a1 < 400) trigFront[0] = true;
  else trigFront[0] = false;
  if (a2 < 400) trigBack[0] = true;
  else trigBack[0] = false;
  if (b1 < 400) trigFront[1] = true;
  else trigFront[1] = false;
  if (b2 < 400) trigBack[1] = true;
  else trigBack[1] = false;
  if (c1 < 400) trigFront[2] = true;
  else trigFront[2] = false;
  if (c2 < 400) trigBack[2] = true;
  else trigBack[2] = false;
  if (d1 < 400) trigFront[3] = true;
  else trigFront[3] = false;
  if (d2 < 400) trigBack[3] = true;
  else trigBack[3] = false;

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

void gychange()
{
  if (lane[0] == 0)
  {

  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  trigFront[0] = false;  // tells if front sensor of lane 1 is triggered
  trigBack[0] = false;   // tells if back sensor of lane 1 is triggered
  trigFront[1] = false;  // tells if front sensor of lane 2 is triggered
  trigBack[1] = false;   // tells if back sensor of lane 2 is triggered
  trigFront[2] = false;  // tells if front sensor of lane 3 is triggered
  trigBack[2] = false;   // tells if back sensor of lane 3 is triggered
  trigFront[3] = false;  // tells if front sensor of lane 4 is triggered
  trigBack[3] = false;   // tells if back sensor of lane 4 is triggered

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

  Serial.println("Starting Several Things At The Same Time");
  lane[0] = a1;  // pin of sensor 1
  lane[1] = b1;  // pin of sensor 2
  lane[2] = c1;  // pin of sensor 3
  lane[3] = d1;  // pin of sensor 4
  beginTime = millis();
  openLane = 1;
}

bool check15seconds() {
  return (curTime - beginTime >= 15000) ? true : false;
}

bool check5seconds(unsigned long backSensorBeginTime) {
  return (curTime - backSensorBeginTime >= 5000) ? true : false;
}

void loop() {
  // put your main code here, to run repeatedly:
  curTime = millis();

  readSensor();
  // 1. check if there is a triggered front sensor, put the sensor in priority list (prioritySensor).
  //.   reset sensor.
  if (lane[0] == true && !trigFront[0]) {
    prioritySensor.enqueue(1);
    trigFront[0] = true;
  }
  if (lane[1] == true && !trigFront[1]) {
    prioritySensor.enqueue(2);
    trigFront[1] = true;
  }
  if (lane[2] == true && !trigFront[2]) {
    prioritySensor.enqueue(3);
    trigFront[2] = true;
  }
  if (lane[3] == true && !trigFront[3]) {
    prioritySensor.enqueue(4);
    trigFront[3] = true;
  }

  // 2. check if there is a queued lane.
  //.   if there is, check if open lane sensor is 0.
  //.   if zero, change LED of priority lane.
  //    remove lane from priority list, reset beginTime.
  if (!prioritySensor.isEmpty()) {
    if (prioritySensor.getHead() != openLane) {
      openLane = prioritySensor.dequeue();
      if (lane[openLane - 1] == 0) {
        delay(timeGreenToYellow);
        // change Green to Yellow;
        digital
          delay(timeYellowToRed);
        // change Yellow to Red;
        //openLane to Red
//          lane[openLane - 1] to Green
            beginTime = millis();
        trigFront[openLane - 1] = false;
      }
    }
  }

  // 3. check if a back sensor is triggered, save time the sensor is triggered (backSensorTime).
  if (lane[0] == 1 && !trigBack[0]) {
    prioritySensor.enqueue(1);
    trigBack[0] = true;
    backSensorTime[0] = millis();
  }
  if (lane[1] == 1 && !trigBack[1]) {
    prioritySensor.enqueue(2);
    trigBack[1] = true;
    backSensorTime[1] = millis();
  }
  if (lane[2] == 1 && !trigBack[2]) {
    prioritySensor.enqueue(3);
    trigBack[2] = true;
    backSensorTime[2] = millis();
  }
  if (lane[3] == 1 && !trigBack[3]) {
    prioritySensor.enqueue(4);
    trigBack[3] = true;
    backSensorTime[3] = millis();
  }

  // 4. If there is a back sensor triggered for more than 5 seconds, move to first priority.
  //.   Adjust other lanes in the priority list.
  ArduinoQueue<int> temp(4);
  if (trigBack[0] && check5seconds(backSensorTime[0])) {
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
  }
  if (trigBack[1] && check5seconds(backSensorTime[1])) {
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
  }
  if (trigBack[2] && check5seconds(backSensorTime[2])) {
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
  }
  if (trigBack[3] && check5seconds(backSensorTime[3])) {
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
  }
  // 5. If there are no changes in LED, force change after 15 seconds.
  if (check15seconds()) {
    delay(timeGreenToYellow);
    // change Green to Yellow;
   // openLane to Yellow
      delay(timeYellowToRed);
    // change Yellow to Red;
    //openLane to Red
 //     lane[x - 1] to Green
        beginTime = millis();
    if (prioritySensor.isEmpty()) {
      openLane = (openLane % 4) + 1;
    } else {
      openLane = prioritySensor.dequeue();
    }
  }
}
