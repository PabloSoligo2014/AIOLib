#include "squeue.h"
#include "utils.h"

void queueCreate(tsqueue* squeue){
    squeue->start   = 0;
    squeue->aend    = 0;
    squeue->available = QSIZE;
}

int queueIsEmpty(const tsqueue* squeue){
    return squeue->available==QSIZE;
}

int queueIsFull(const tsqueue* squeue, size_t asize){
    return squeue->available<asize+sizeof(size_t);
}

int queuePush(tsqueue* squeue, const void* data, size_t asize){
    size_t _firstPart;
    size_t _endPart;

    if (squeue->available<asize+sizeof(size_t)){
        return 0;
    }
    squeue->available -= sizeof(size_t)+asize;
    if( (_firstPart=MIN(sizeof(size_t), QSIZE-squeue->aend))!=0 ){
        _memcpy(squeue->squeue+squeue->aend, &asize, _firstPart);
    }

    if((_endPart=sizeof(asize)-_firstPart)!=0){
        _memcpy(squeue->squeue, ((uint8_t*)&asize + _firstPart), _endPart);
    }

    //TODO pasar a usar operador modulo
    squeue->aend = _endPart?_endPart:squeue->aend+_firstPart;

    if( (_firstPart=MIN(sizeof(asize), QSIZE-squeue->aend))!=0 ){
        _memcpy(squeue->squeue+squeue->aend, data, _firstPart);
    }

    if((_endPart=sizeof(asize)-_firstPart)!=0){
        _memcpy(squeue->squeue, ((uint8_t*)data + _firstPart), _endPart);
    }
    //TODO pasar a usar operador modulo
    squeue->aend = (squeue->aend+asize)%QSIZE;
    //squeue->aend = _endPart?_endPart:squeue->aend+_firstPart;
    return 1;
}

int queuePop(tsqueue* squeue, void* data, size_t asize){
    size_t _firstPart;
    size_t _endPart;
    size_t dsize;
    size_t fsize;
    if (squeue->available==QSIZE){
        return 0;
    }

    squeue->available += sizeof(size_t);
    if( (_firstPart=MIN(sizeof(size_t), QSIZE-squeue->start))!=0 ){
        _memcpy(&dsize, squeue->squeue+squeue->start, _firstPart);
    }

    if((_endPart=sizeof(size_t)-_firstPart)!=0){
        _memcpy(&dsize+_firstPart, squeue->squeue, _endPart);
    }

    squeue->start =  (squeue->start+sizeof(size_t))%QSIZE;
    squeue->available += dsize;
    fsize = MIN(asize, dsize);

    if( (_firstPart=MIN(fsize, QSIZE-squeue->start))!=0 ){
        _memcpy(data, squeue->squeue+squeue->start, _firstPart);
    }

    if((_endPart=fsize-_firstPart)!=0){
        _memcpy((uint8_t*)data+_firstPart, squeue->squeue, _endPart);
    }
    //TODO pasar a usar operador modulo
    squeue->start = (squeue->start+asize)%QSIZE;
    //squeue->aend = _endPart?_endPart:squeue->aend+_firstPart;
    return 1;

}


int queuePeek(tsqueue* squeue, void* data, size_t asize){
    size_t _firstPart;
    size_t _endPart;
    size_t dsize;
    size_t fsize;
    if (squeue->available==QSIZE){
        return 0;
    }

    if( (_firstPart=MIN(sizeof(size_t), QSIZE-squeue->start))!=0 ){
        _memcpy(&dsize, squeue->squeue+squeue->start, _firstPart);
    }

    if((_endPart=sizeof(size_t)-_firstPart)!=0){
        _memcpy(&dsize+_firstPart, squeue->squeue, _endPart);
    }

    fsize = MIN(asize, dsize);

    if( (_firstPart=MIN(fsize, QSIZE-squeue->start+sizeof(size_t)))!=0 ){
        _memcpy(data, squeue->squeue+squeue->start+sizeof(size_t), _firstPart);
    }

    if((_endPart=fsize-_firstPart)!=0){
        _memcpy((uint8_t*)data+_firstPart, squeue->squeue, _endPart);
    }
    return 1;

}
