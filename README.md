# AIOLib

Pure and generic lightweight C queue and stack. Meant for microcontrollers, low level, critical or real time software without dynamic memory.

# How to use
Change the QSIZE or SSIZE value according on the expected maximum size or software/hardware limitations.

#define SSIZE 40
#define QSIZE 70

Declare and create the queue.

tsstack sstack;
tsqueue squeue;
queueCreate(&squeue);
stackCreate(&sstack);

# Thread safety
This library is not thread safe.

# Performance
