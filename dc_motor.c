#include "dc_motor.h"
#include "gpio.h"
#include <avr/io.h>
#include "pwm.h"


/*Description

The Function responsible for
   setup the direction for the two motor pins through the GPIO driver.
   Stop at the DC-Motor at the beginning through the GPIO driver
 */
void DcMotor_Init(void)
{

	GPIO_setupPinDirection(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN,PIN_OUTPUT);

	GPIO_setupPinDirection(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN,PIN_OUTPUT);

	GPIO_writePin(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN,LOGIC_LOW); //To make the DC Motor Stopped Initially

}

/*Description

 The function responsible for:
  -rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value
  -Send the required duty cycle to the PWM driver based on the required speed value.
   speed: decimal value for the required motor speed, it should be from 0 → 100.
    For example, if the input is 50, The motor should rotate with 50% of its maximum speed.

 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state==STOP)
	{
		GPIO_writePin(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN,LOGIC_LOW);

	}
	else if(state==CW)
	{
		GPIO_writePin(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN,LOGIC_LOW);
	}
	else if(state==ACW)
	{
		GPIO_writePin(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN,LOGIC_HIGH);
	}
	PWM_Timer0_Start(speed);
}
