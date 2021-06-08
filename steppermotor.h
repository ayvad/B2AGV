/*
*   Code made by Ayke Vaders
*   HHS MeP2.B2 2020-2021 AGV Steppermotor
*   Studentcode: 20195613
*/

#ifndef STEPPERMOTOR_H_INCLUDED
#define STEPPERMOTOR_H_INCLUDED

#define delaytime_stepper 1000      // in useconds
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

void init_steppermotor(void);

void steppermotor1Write(int a);
void steppermotor2Write(int a);
void steppermotor3Write(int a);
void steppermotor4Write(int a);

//512 is een rondje.
void Vooruit(int Steppermotortijd);
void Achteruit(int Steppermotortijd);
void Rechtsaf(int Steppermotortijd);
void Linksaf(int Steppermotortijd);


#endif
