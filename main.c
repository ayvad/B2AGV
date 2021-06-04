#include <avr/io.h>
#include <util/delay.h>
#include  "ultrasoon.h"
#include <avr/interrupt.h>
#include "steppermotor.h"

//#define delaytime_stepper 1000
#define distance_dangerzone 15

//Ultrasoon1 Trigger PD0        pin 21
//Ultrasoon1 Echo PCINT0        pin 53
//Ultrasoon2 Trigger PD1        pin 20
//Ultrasoon2 Echo PCINT1        pin 52

/*
#define PStepper1_1 PC7     //pin 30
#define PStepper1_2 PC5     //pin 32
#define PStepper1_3 PC3     //pin 34
#define PStepper1_4 PC1     //pin 36

#define PStepper2_1 PC6     //pin 31
#define PStepper2_2 PC4     //pin 33
#define PStepper2_3 PC2     //pin 35
#define PStepper2_4 PC0     //pin 37

#define PStepper3_1 PL7     //pin 42
#define PStepper3_2 PL5     //pin 44
#define PStepper3_3 PL3     //pin 46
#define PStepper3_4 PL1     //pin 48

#define PStepper4_1 PL6     //pin 43
#define PStepper4_2 PL4     //pin 45
#define PStepper4_3 PL2     //pin 47
#define PStepper4_4 PL0     //pin 49

#define DDRStepper1 DDRC
#define DDRStepper2 DDRC
#define DDRStepper3 DDRL
#define DDRStepper4 DDRL

#define PORTStepper1 PORTC
#define PORTStepper2 PORTC
#define PORTStepper3 PORTL
#define PORTStepper4 PORTL

*/

#define PIRsensor1 PJ0          //pin 15
#define PIRsensor2 PJ1          //pin 14

#define PLEDRoodVoor PA0        //pin 22
#define PLEDRoodAchter PA1     //pin 23
#define PLEDRoodRechts PA2     //pin 24
#define PLEDRoodLinks PA3           //pin 25

#define PLEDGeelVoor PA4            //pin 26
#define PLEDGeelAchter PA5          //pin 27
#define PLEDGeelRechts PA6          //pin 28
#define PLEDGeelLinks PA7          //pin 29

#define PLEDNoodstop PE4           //pin 2
#define PNoodstop PE3                   //pin 5

#define DDRIRsensor1 DDRJ
#define DDRIRsensor2 DDRJ

#define DDRLEDRood DDRA
#define DDRLEDGeel DDRA
#define DDRLEDNoodstop DDRE
#define DDRNoodstop DDRE

#define PORTLEDRood PORTA
#define PORTLEDGeel PORTA
#define PORTLEDNoodstop PORTE

#define PINNoodstop PINE

#define PINIRsensor1 PINJ
#define PINIRsensor2 PINJ

void LED(int Richting)
{
    switch (Richting)
    {
    case 1 :
        PORTLEDRood &= ~(1 << PLEDRoodVoor);
        PORTLEDRood |= (1 << PLEDRoodAchter);
        PORTLEDRood &= ~(1 << PLEDRoodRechts);
        PORTLEDRood &= ~(1 << PLEDRoodLinks);

        PORTLEDGeel |= (1 << PLEDGeelVoor);
        PORTLEDGeel &= ~(1 << PLEDGeelAchter);
        PORTLEDGeel &= ~(1 << PLEDGeelRechts);
        PORTLEDGeel &= ~(1 << PLEDGeelLinks);
        break;
    case 2 :
        PORTLEDRood |= (1 << PLEDRoodVoor);
        PORTLEDRood &= ~(1 << PLEDRoodAchter);
        PORTLEDRood &= ~(1 << PLEDRoodRechts);
        PORTLEDRood &= ~(1 << PLEDRoodLinks);

        PORTLEDGeel &= ~(1 << PLEDGeelVoor);
        PORTLEDGeel |= (1 << PLEDGeelAchter);
        PORTLEDGeel &= ~(1 << PLEDGeelRechts);
        PORTLEDGeel &= ~(1 << PLEDGeelLinks);
        break;
    case 3 :
        PORTLEDRood &= ~(1 << PLEDRoodVoor);
        PORTLEDRood &= ~(1 << PLEDRoodAchter);
        PORTLEDRood &= ~(1 << PLEDRoodRechts);
        PORTLEDRood |= (1 << PLEDRoodLinks);

        PORTLEDGeel &= ~(1 << PLEDGeelVoor);
        PORTLEDGeel &= ~(1 << PLEDGeelAchter);
        PORTLEDGeel |= (1 << PLEDGeelRechts);
        PORTLEDGeel &= ~(1 << PLEDGeelLinks);
        break;
    case 4 :
        PORTLEDRood &= ~(1 << PLEDRoodVoor);
        PORTLEDRood &= ~(1 << PLEDRoodAchter);
        PORTLEDRood |= (1 << PLEDRoodRechts);
        PORTLEDRood &= ~(1 << PLEDRoodLinks);

        PORTLEDGeel &= ~(1 << PLEDGeelVoor);
        PORTLEDGeel &= ~(1 << PLEDGeelAchter);
        PORTLEDGeel &= ~(1 << PLEDGeelRechts);
        PORTLEDGeel |= (1 << PLEDGeelLinks);
        break;
    case 5 :
        PORTLEDRood |= (1 << PLEDRoodVoor);
        PORTLEDRood |= (1 << PLEDRoodAchter);
        PORTLEDRood |= (1 << PLEDRoodRechts);
        PORTLEDRood |= (1 << PLEDRoodLinks);

        PORTLEDGeel &= ~(1 << PLEDGeelVoor);
        PORTLEDGeel &= ~(1 << PLEDGeelAchter);
        PORTLEDGeel &= ~(1 << PLEDGeelRechts);
        PORTLEDGeel &= ~(1 << PLEDGeelLinks);
        break;
    case 6 :
        PORTLEDRood |= (1 << PLEDRoodVoor);
        PORTLEDRood |= (1 << PLEDRoodAchter);
        PORTLEDRood |= (1 << PLEDRoodRechts);
        PORTLEDRood |= (1 << PLEDRoodLinks);

        PORTLEDGeel |= (1 << PLEDGeelVoor);
        PORTLEDGeel |= (1 << PLEDGeelAchter);
        PORTLEDGeel |= (1 << PLEDGeelRechts);
        PORTLEDGeel |= (1 << PLEDGeelLinks);
        break;
    default :
        PORTLEDRood |= (1 << PLEDRoodVoor);
        PORTLEDRood |= (1 << PLEDRoodAchter);
        PORTLEDRood |= (1 << PLEDRoodRechts);
        PORTLEDRood |= (1 << PLEDRoodLinks);

        PORTLEDGeel &= ~(1 << PLEDGeelVoor);
        PORTLEDGeel &= ~(1 << PLEDGeelAchter);
        PORTLEDGeel &= ~(1 << PLEDGeelRechts);
        PORTLEDGeel &= ~(1 << PLEDGeelLinks);
        }
}

void init(void)
{
    LED(5);
    DDRLEDRood |= (1 << PLEDRoodVoor);
    DDRLEDRood |= (1 << PLEDRoodAchter);
    DDRLEDRood |= (1 << PLEDRoodRechts);
    DDRLEDRood |= (1 << PLEDRoodLinks);

    DDRLEDRood |= (1 << PLEDNoodstop);

    init_ultrasoon();
    sei();
}

int main(void)
{
    //int Steps = 512;//512 is een rondje.
    init();

    while(1)
    {
        double distanceUS1 = 0;
        double distanceUS2 = 0;
        distanceUS1 = distance(ultra_1_trigger);
        distanceUS2 = distance(ultra_2_trigger);
        while((distanceUS1 > distance_dangerzone) & (distanceUS2 > distance_dangerzone))
        {
            LED(1);
            while ( !(PINIRsensor1 && (1 << PIRsensor1) ) )
            {
                Vooruit(100);
                distanceUS1 = distance(ultra_1_trigger);
                distanceUS2 = distance(ultra_2_trigger);
            }
            LED(5);
            distanceUS1 = distance(ultra_1_trigger);
            distanceUS2 = distance(ultra_2_trigger);
        }
    }
    return 0;
}
