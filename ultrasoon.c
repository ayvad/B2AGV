/*
*       Made by Daan Sijnja
*       Student at HHS
*       Studentcode: 20177747
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include  "ultrasoon.h"

static volatile unsigned long pulse = 0; //the variable for the pulse
static volatile int echo_pin = 0; //logic for the ultrasoon
volatile int isTriggerd = 0;    // used in the while loop
volatile int overflows = 0;

int distance(int triggerpin) {

    switch(triggerpin)
    {
        case ultra_1_trigger:
            PCMASK = 0;
            PCMASK = ultra_1_pin;
        break;

        case ultra_2_trigger:
            PCMASK = 0;
            PCMASK = ultra_2_pin;
        break;
    }

    TRIGGERPORT |= (1 << triggerpin);
    _delay_us(15);
    TRIGGERPORT &= ~( 1 << triggerpin);
    isTriggerd = 1;
    _delay_us(15);

    unsigned long i = 0;
    while(isTriggerd){
       if(i > ((RETURNVALUE+10)*16))
       {
           PCMASK = 0;
           return RETURNVALUE;
       }
       i++;

    }

    return pulse/928.0;
}
void init_ultrasoon(){
    TRIGGERDDR |= (1 << ultra_1_trigger) | (1 << ultra_2_trigger);
    TRIGGERPORT &= ~(1 << ultra_1_trigger);
    TRIGGERPORT &= ~(1 << ultra_2_trigger);
    PCICR |= (1 << PCREG);
    PCMASK = 0;
}

ISR(PCISR)   // Interrupt service routine.
{
    if (echo_pin==1)
	{
		TIMER_B = 0;    //TIMER COUNTER CONTROL REGITER (Stop the counter)
		pulse=TNCT_timer+(overflows*OVERFLOW);  // store the value of counter
		TNCT_timer=0;     // reset the counter
		echo_pin=0;
		isTriggerd = 0;
		overflows = 0;
	}
	else
	{
		TIMER_B |=(1<<CS10);  // used to start the internal counter of microcontroller
		TIMSK_timer = (1 <<TIMSK_bit);
		echo_pin=1;
	}
}

ISR(ISR_TIMER_OVF){
    overflows++;
}


