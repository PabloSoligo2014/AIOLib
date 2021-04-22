# AIOLib

Pure and generic lightweight C queue and stack. Meant for microcontrollers, low level, critical or real time software without dynamic memory. Support any data type and and can efficiently store variable size elements like null terminated array char. (See the example). The library create his own copy, don't worry about data scope.

# How to use
## Queue
Change the QSIZE (in bytes) in squeue.h according on the expected maximum size or software/hardware limitation.
```
#define QSIZE 70
```
then declare and create the queue when you need, typical push, pop, isFull, isEmpty methods are available.
```
tsqueue squeue;
queueCreate(&squeue);
int x = 8;
if(!queuePush(&squeue, &vec[i], sizeof(vec[i]))){
    if(queuePop(&squeue, &val, sizeof(val))){
        printf("Quitado:%5.2f\n", val);
    }
}else{
    //there is not storage space available
}


```

```
#define SSIZE 40
```
# Thread safety
This library is not thread safe.

# Performance
