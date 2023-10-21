
#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

/*
 Define the port and the pin in which the PWM will be generated
 */

#define PWM_TIMER0_OUTPUT_SIGNAL_PORT        PORTB_ID
#define PWM_TIMER0_OUTPUT_SIGNAL_PIN         PIN3_ID  /*OC0*/
#define TOP_VALUE                            0xFF


void PWM_Timer0_Start(uint8 duty_cycle);



#endif /* PWM_H_ */
