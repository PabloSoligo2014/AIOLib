#ifndef SQUEUE_H_INCLUDED
#define SQUEUE_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>

#define QSIZE 40

typedef struct{
    size_t start;
    size_t aend;
    size_t available;
    uint8_t squeue[QSIZE];
}tsqueue;

void queueCreate(tsqueue* squeue);
int queueIsFull(const tsqueue* squeue, size_t asize);
int queueIsEmpty(const tsqueue* squeue);
int queuePush(tsqueue* squeue, const void* data, size_t asize);
int queuePop(tsqueue* squeue, void* data, size_t asize);
int queuePeek(tsqueue* squeue, void* data, size_t asize);
/*
empty
size
front
back
push_back
pop_front
*/

#endif // SQUEUE_H_INCLUDED
