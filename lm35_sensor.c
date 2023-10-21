#include "lm35_sensor.h"
#include "lcd.h"
#include "adc.h"


uint8 LM35_getTemperature(void)
{

uint16 adc_value=0;
uint8 temperature_value=0;

adc_value=ADC_readChannel(SENSOR_CHANNEL_ID);


temperature_value= (uint8)(((uint32)SENSOR_MAX_TEMPERATURE*adc_value*INTERNAL_VOLTAGE)/(ADC_MAX_BITS*SENSOR_MAX_VOLTAGE));


return temperature_value;

}
