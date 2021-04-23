# AIOLib

Pure and generic lightweight C queue and stack. Meant for microcontrollers (like arduino), low level, critical or real time software without dynamic memory. Support any data type and and can efficiently store variable size elements like null terminated array char. (See the example). The library create his own copy, don't worry about data scope.

# Libraries availables
## sstack
Pure C stack, only stack memory, no dynamic memory required.

## squeue
Pure C queue, only stack memory, no dynamic memory required.

## TStack
Hybrid/Object oriented stack, create to simplify final code and avoid order call problems (if constructor call is available on platform). 

# How to use
## squeue
Change the QSIZE (in bytes) in squeue.h according on the expected maximum size or software/hardware limitation.
```
#define QSIZE 70
```
then declare and create the queue when you need, typical push, pop, isFull, isEmpty methods are available.
```
tsqueue squeue;
queueCreate(&squeue);
int x = 8;
```

# Thread safety
This library is not thread safe.

# Performance
