#include "ch.h"
#include "hal.h"
#include "MessageManagement.h"

/*
 * Application entry point.
 */
int main(void) {
  halInit();
  chSysInit();

  /*
   * Set mode of onboard LED
   */
  palSetPadMode(ONBOARD_LED_PORT, ONBOARD_LED_PAD, PAL_MODE_OUTPUT);
  
  start_message_management_thread();
  /*
   * Events servicing loop.
   */
  chThdWait(chThdSelf());

  return 0;
}
