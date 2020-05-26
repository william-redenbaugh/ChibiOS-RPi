#include "MessageManagement.h"

void start_message_management_thread(void);

static WORKING_AREA(message_thread_wa, 2048);
static msg_t MessageThread(void *parameters){
    (void)parameters; 
    chRegSetThreadName("Message Management Thread");

    while(true){
        palClearPad(ONBOARD_LED_PORT, ONBOARD_LED_PAD);
        chThdSleepMilliseconds(10);
        palSetPad(ONBOARD_LED_PORT, ONBOARD_LED_PAD);
        chThdSleepMilliseconds(10);
    }
}


void start_message_management_thread(void){
    chThdCreateStatic(message_thread_wa, sizeof(message_thread_wa), NORMALPRIO, MessageThread, NULL);
}