#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/sstack.h"
#include "../../src/squeue.h"

int main()
{
    float vec[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    char palabras[7][17] = {{"El"},
                           {"Fuego"},
                           {"Camilo"},
                           {"Sabana"},
                           {"Ana"},
                           {"Nadie lo sabe"},
                           {"Alternativa"}};
    char cad[17];

    float val;
    tsstack sstack;
    tsqueue squeue;
    queueCreate(&squeue);
    stackCreate(&sstack);


    int i;

    for(i=0;i<sizeof(vec)/sizeof(float);i++){
        if(!stackPush(&sstack, &vec[i], sizeof(vec[i]))){
            break;
        }
    }

    stackPeek(&sstack, &val, sizeof(val));
    printf("peek %5.2f\n", val);


    while(stackPop(&sstack, &val, sizeof(val))){
        printf("Desapilado %5.2f\n", val);
    }

    stackClear(&sstack);


    for(i=0;i<7;i++){
        if(!stackPush(&sstack, palabras[i], strlen(palabras[i])+1)){
            break;
        }
    }

    while(stackPop(&sstack, cad, 17)){
        printf("Desapilado %s\n", cad);
    }



    for(i=0;i<sizeof(vec)/sizeof(float);i++){
        if(!queuePush(&squeue, &vec[i], sizeof(vec[i]))){
            printf("No puesto:%5.2f\n", vec[i]);
            if(queuePop(&squeue, &val, sizeof(val))){
                printf("Quitado:%5.2f\n", val);
            }
        }
        if(queuePeek(&squeue, &val, sizeof(val))){
            printf("Picado:%5.2f\n", val);
        }
    }


    while(!queueIsEmpty(&squeue)){
        if(queuePeek(&squeue, &val, sizeof(val))){
            printf("Picado:%5.2f\n", val);
        }
        queuePop(&squeue, &val, sizeof(val));
        printf("desencolando: %5.2f\n", val);
    }

    printf("Hello world!\n");
    return 0;
}
