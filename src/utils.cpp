#include "utils.h"
#include <stdint.h>

void* _memcpy(void* dest, const void* source, size_t asize){
    unsigned int i;
    uint8_t* uidest     = (uint8_t*)dest;
    uint8_t* uisource   = (uint8_t*)source;
    for(i=0;i<asize;i++){
        *uidest = *uisource;
        uidest++;
        uisource++;
    }
    return (uint8_t*)dest-asize;
}
