#include <squeue.h>


tsqueue squeue;

void setup() {
  // put your setup code here, to run once:
  
  queueCreate(&squeue);
}

void loop() {
  double p = 0.0;
  int i = 0;
  //fill the queue
  while(queuePush(&squeue, &p, sizeof(p))){
    i++;
  }
  
  
  Serial.print("last value:");
  
}
