#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include "common_macros.h"

#define DC_MOTOR_INPUT1_PORT       PORTB_ID
#define DC_MOTOR_INPUT1_PIN        PIN0_ID

#define DC_MOTOR_INPUT2_PORT       PORTB_ID
#define DC_MOTOR_INPUT2_PIN        PIN1_ID

/*
The DC Motor state should be CW or A-CW or stop.
  */

typedef enum{
	STOP,CW,ACW
}DcMotor_State;



void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_MOTOR_H_ */
