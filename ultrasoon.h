/*
*       Made by Daan Sijnja
*       Student at HHS
*       Studentcode: 20177747
*       Github: DaanSijnja/Ultrasoon_AVR
*/

#ifndef ULTRASOON_H_INCLUDED
#define ULTRASOON_H_INCLUDED


//settings pins **make sure you use the trigger pins on one Register like the D register
    #define TRIGGERDDR DDRD
    #define TRIGGERPORT PORTD
    #define ultra_1_trigger PD0 //trigger pins for the ultrasoon 1    pin 21
    #define ultra_2_trigger PD1 // if you need a second ultrasoon   pin 20

    #define RETURNVALUE 60

//settings PCINT ** I recommend you to use PCINT0 because its one of the few PCINT'S that is one Register and not spread between multiple
    #define PCDDR DDRB
    #define PCPIN PINB
    #define PCREG PCIE0 //the Pin Change Interrupt Control Register
    #define PCMASK PCMSK0 //the Pin Change Mask Register
    #define PCISR PCINT0_vect
    //ultrasoon/ultrasonen
        #define ultra_1_pin (1 << PCINT0) //The pin of the echo from the first ultrasoon            //pin 53
        #define ultra_2_pin (1 << PCINT1) //The pin of the echo from the second ultrasoon      //pin 52


//settings timer **use a 16 bit timer ** if you want to use a other timer you need to change the 5 to you're timer NOTE: if you use an 8 bit timer you need to change OVERFLOW to 255
    #define TIMER_B TCCR5B
    #define TIMSK_timer TIMSK5
    #define TNCT_timer TCNT5
    #define TIMSK_bit TOIE5
    //settings ISR timer
    #define ISR_TIMER_OVF TIMER5_OVF_vect
    //Advanced settings timer
        #define OVERFLOW 65535


int distance(int triggerpin);
void init_ultrasoon(void); // inits the ultrasoon


#endif // ULTRASOON_H_INCLUDED
