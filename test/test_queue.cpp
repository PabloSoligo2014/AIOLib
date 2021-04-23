#include <Arduino.h>
#include <unity.h>


#include "squeue.h"
// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

//Redefine QSIZE

float vec[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
tsqueue queue;


void test_push_until_full(void) {
    int i;
    for(i=0;i<sizeof(vec)/sizeof(vec[0]);i++){
        if(!queuePush(&queue, &vec[i], sizeof(float))){
            break;
        }
    }

    TEST_ASSERT_EQUAL(i, QSIZE/sizeof(float));
}


void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    
    UNITY_BEGIN();    // IMPORTANT LINE!
    //RUN_TEST(test_led_builtin_pin_number);
    queueCreate(&queue);
    //pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 2;

void loop() {

    RUN_TEST(test_push_until_full);
    UNITY_END();
    
    /*
    if (i < max_blinks)
    {
        RUN_TEST(test_push_until_full);
        delay(500);
       
        i++;
    }
    else if (i == max_blinks) {
      UNITY_END(); // stop unit testing
    }
    */
}