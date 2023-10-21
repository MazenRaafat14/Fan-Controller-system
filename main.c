#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "adc.h"



int main()
{
	DcMotor_State motor_state;
	uint8 temperature;

	LCD_init();
	DcMotor_Init();

	ADC_configType adc_configuration;
	adc_configuration.ref_voltage=INTERNAL;
	adc_configuration.prescaler=F_CPU_CLOCK_128;
	ADC_init(&adc_configuration);

	while(1)
	{
		/*
		 getting the Temperature from the sensor and based on it, The DC-Motor will Operate
		 */

		temperature= LM35_getTemperature();

		if(temperature<30)
		{
			motor_state=STOP;
			DcMotor_Rotate(motor_state,0);
		}
		else if(temperature>=30 && temperature<60)
		{
			motor_state=CW;
			DcMotor_Rotate(motor_state,25);

		}
		else if(temperature>=60 && temperature<90)
		{
			motor_state=CW;
			DcMotor_Rotate(motor_state,50);

		}
		else if(temperature>=90 && temperature<120)
		{
			motor_state=CW;
			DcMotor_Rotate(motor_state,75);
		}
		else if(temperature>=120)
		{
			motor_state=CW;
			DcMotor_Rotate(motor_state,100);
		}


		if (motor_state==STOP)
		{
			LCD_displayStringRowColumn(0,4,"FAN is OFF");
		}
		else
		{
			LCD_displayStringRowColumn(0,4,"FAN is ON");
			LCD_displayCharacter(' ');

		}

		/*
		 Display the Temperature on the LCD
		 */

		LCD_displayStringRowColumn(1,4,"Temp = ");


		/*
		 This condition is just for the case such that the temperature decreased from 100, so the first number from the right of the temperature
		 must be cleared
		 */
		if(temperature>100)
		{
			LCD_intgerToString(temperature);

		}

		else
		{
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}

	}

}
