#include "TStack.h"
#include "utils.h"

TStack::TStack(){
    this->top = SSIZE;
}

void TStack::begin(){
    this->top = SSIZE;
}

int TStack::push(const void* data, unsigned int asize){
    if (this->top<asize+sizeof(unsigned int)){
        return 0;
    }

    this->top -= asize;

    _memcpy(this->sstack+this->top, data, asize);
    this->top -= sizeof(unsigned int);
    _memcpy(this->sstack+this->top, &asize, sizeof(unsigned int));

    return 1;
}

int TStack::pop(void* data, unsigned int asize){
    unsigned int dataSize;
    if (this->top==SSIZE){
        return 0;
    }

    _memcpy(&dataSize, this->sstack+this->top, sizeof(unsigned int));
    this->top += sizeof(unsigned int);

    _memcpy(data, this->sstack+this->top, MIN(dataSize, asize));
    this->top += dataSize;

    return 1;
}

int TStack::peek(void* data, unsigned int asize){
    unsigned int dataSize;
    if(this->top==SSIZE)
        return 0;

    _memcpy(&dataSize, this->sstack+this->top, sizeof(unsigned int));
    _memcpy(data, this->sstack+this->top+sizeof(unsigned int), MIN(dataSize, asize));
    return 1;

}

int TStack::isFull(unsigned int asize){
    return this->top<sizeof(unsigned int)+asize;
}


int TStack::isEmpty(){
    return this->top==SSIZE;
}

void TStack::clean(){
    this->top = SSIZE;
}
