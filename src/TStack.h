#ifndef TSTACK_H_INCLUDED
#define TSTACK_H_INCLUDED
#include <stdint.h>
#define SSIZE 40

class TStack{

    private:
        uint8_t sstack[SSIZE];
        unsigned int top;

    public:
        TStack();
        void begin();
        int push(const void* data, unsigned int asize);
        int pop(void* data, unsigned int asize);
        int peek(void* data, unsigned int asize);
        int isFull(unsigned int asize);
        int isEmpty();
        void clean();
};


#endif // TSTACK_H_INCLUDED
