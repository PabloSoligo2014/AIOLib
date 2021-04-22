#ifndef SSTACK_H_INCLUDED
#define SSTACK_H_INCLUDED

#include <stdint.h>


#define SSIZE 40



typedef struct{
    uint8_t sstack[SSIZE];
    unsigned int top;
}tsstack;

void stackCreate(tsstack* sstack);
int stackPush(tsstack* sstack, const void* data, unsigned int asize);
int stackPop(tsstack* sstack, void* data, unsigned int asize);
int stackPeek(const tsstack* sstack, void* data, unsigned int asize);
int stackIsFull(const tsstack* sstack, unsigned int asize);
int stackIsEmpty(const tsstack* sstack);
void stackClear(tsstack* sstack);


#endif // SSTACK_H_INCLUDED
