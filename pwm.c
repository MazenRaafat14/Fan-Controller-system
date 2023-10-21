#include "pwm.h"
#include "gpio.h"
#include <avr/io.h>


/*
 Description
 The function responsible for trigger the Timer0 with the PWM Mode.

 */


void PWM_Timer0_Start(uint8 duty_cycle)
{
	/*
	 PWM mode -----> WGM00=1, WGM01=1
	 Non-Inverting PWM ---->COM01=1, COM00=0
	 Prescaler FCPU/8 -----> CS00=0, CS01=1, CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	TCNT0=0;
	/*
	put The value of the duty cycle represents % of the TOP value of the TIMER0 in the Compare register of Timer 0
	 */
	OCR0=((duty_cycle*TOP_VALUE)/100);
	GPIO_setupPinDirection(PWM_TIMER0_OUTPUT_SIGNAL_PORT,PWM_TIMER0_OUTPUT_SIGNAL_PIN,PIN_OUTPUT);

}
