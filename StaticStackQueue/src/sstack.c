#include "sstack.h"

#include "utils.h"


void stackCreate(tsstack* sstack){
    sstack->top = SSIZE;
}

int stackPush(tsstack* sstack, const void* data, unsigned int asize){
    if (sstack->top<asize+sizeof(unsigned int)){
        return 0;
    }

    sstack->top -= asize;
    _memcpy(sstack->sstack+sstack->top, data, asize);
    sstack->top -= sizeof(unsigned int);
    _memcpy(sstack->sstack+sstack->top, &asize, sizeof(unsigned int));

    return 1;
}

int stackPop(tsstack* sstack, void* data, unsigned int asize){

    unsigned int dataSize;
    if (sstack->top==SSIZE){
        return 0;
    }

    _memcpy(&dataSize, sstack->sstack+sstack->top, sizeof(unsigned int));
    sstack->top += sizeof(unsigned int);

    _memcpy(data, sstack->sstack+sstack->top, MIN(dataSize, asize));
    sstack->top += dataSize;

    return 1;
}


int stackPeek(const tsstack* sstack, void* data, unsigned int asize){
    unsigned int dataSize;
    if(sstack->top==SSIZE)
        return 0;

    _memcpy(&dataSize, sstack->sstack+sstack->top, sizeof(unsigned int));
    _memcpy(data, sstack->sstack+sstack->top+sizeof(unsigned int), MIN(dataSize, asize));
    return 1;

}


int stackIsFull(const tsstack* sstack, unsigned int asize){
    return sstack->top<sizeof(unsigned int)+asize;
}

int stackIsEmpty(const tsstack* sstack){
    return sstack->top==SSIZE;
}

void stackClear(tsstack* sstack){
    sstack->top = SSIZE;
}
