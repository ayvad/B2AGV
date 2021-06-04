/*
*   Code made by Ayke Vaders
*   HHS MeP2.B2 2020-2021 AGV Steppermotor
*   Studentcode: 20195613
*/



#include <avr/io.h>
#include <util/delay.h>
#include "steppermotor.h"


void init_steppermotor(void)
{
    DDRStepper1 |= (1 << PStepper1_1); // PIN 30
    DDRStepper1 |= (1 << PStepper1_2); // PIN 32
    DDRStepper1 |= (1 << PStepper1_3); // PIN 34
    DDRStepper1 |= (1 << PStepper1_4); // PIN 36

    DDRStepper2 |= (1 << PStepper2_1); // PIN 31
    DDRStepper2 |= (1 << PStepper2_2); // PIN 33
    DDRStepper2 |= (1 << PStepper2_3); // PIN 35
    DDRStepper2 |= (1 << PStepper2_4); // PIN 37

    DDRStepper3 |= (1 << PStepper3_1); // PIN 42
    DDRStepper3 |= (1 << PStepper3_2); // PIN 44
    DDRStepper3 |= (1 << PStepper3_3); // PIN 46
    DDRStepper3 |= (1 << PStepper3_4); // PIN 48

    DDRStepper3 |= (1 << PStepper3_1); // PIN 43
    DDRStepper3 |= (1 << PStepper3_2); // PIN 45
    DDRStepper3 |= (1 << PStepper3_3); // PIN 47
    DDRStepper3 |= (1 << PStepper3_4); // PIN 49
}

void steppermotor1Write(int a)
{
    while(a  == 1)
    {
        int i;
        for(i = 1; i < 8; i=i+1)
        {
            switch (i)
            {
            case 1 :
                PORTStepper1 |= (1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 2 :
                PORTStepper1 |= (1 << PStepper1_1);
                PORTStepper1 |= (1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 3 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 |= (1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 4 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 |= (1 << PStepper1_2);
                PORTStepper1 |= (1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 5 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 |= (1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 6 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 |= (1 << PStepper1_3);
                PORTStepper1 |= (1 << PStepper1_4);
                break;
            case 7 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 |= (1 << PStepper1_4);
                break;
            case 8 :
                PORTStepper1 |= (1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 |= (1 << PStepper1_4);
                break;
            }
            _delay_us(delaytime_stepper);
        }
        a = 0;
    }
    while(a  == 2)
    {
        int i;
        for(i = 8; i > 0; --i)
        {
            switch (i)
            {
            case 8 :
                PORTStepper1 |= (1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 1 :
                PORTStepper1 |= (1 << PStepper1_1);
                PORTStepper1 |= (1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 2 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 |= (1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 3 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 |= (1 << PStepper1_2);
                PORTStepper1 |= (1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 4 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 |= (1 << PStepper1_3);
                PORTStepper1 &= ~(1 << PStepper1_4);
                break;
            case 5 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 |= (1 << PStepper1_3);
                PORTStepper1 |= (1 << PStepper1_4);
                break;
            case 6 :
                PORTStepper1 &= ~(1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 |= (1 << PStepper1_4);
                break;
            case 7 :
                PORTStepper1 |= (1 << PStepper1_1);
                PORTStepper1 &= ~(1 << PStepper1_2);
                PORTStepper1 &= ~(1 << PStepper1_3);
                PORTStepper1 |= (1 << PStepper1_4);
                break;
            }
            _delay_us(delaytime_stepper);
        }
        a = 0;
    }
}

void steppermotor2Write(int a)
{
    while(a  == 1)
    {
        int i;
        for(i = 1; i < 8; i=i+1)
        {
            switch (i)
            {
            case 1 :
                PORTStepper2 |= (1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 2 :
                PORTStepper2 |= (1 << PStepper2_1);
                PORTStepper2 |= (1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 3 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 |= (1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 4 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 |= (1 << PStepper2_2);
                PORTStepper2 |= (1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 5 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 |= (1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 6 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 |= (1 << PStepper2_3);
                PORTStepper2 |= (1 << PStepper2_4);
                break;
            case 7 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 |= (1 << PStepper2_4);
                break;
            case 8 :
                PORTStepper2 |= (1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 |= (1 << PStepper2_4);
                break;
            }
            _delay_us(delaytime_stepper);
        }
        a = 0;
    }
    while(a  == 2)
    {
        int i;
        for(i = 8; i > 0; --i)
        {
            switch (i)
            {
            case 8 :
                PORTStepper2 |= (1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 1 :
                PORTStepper2 |= (1 << PStepper2_1);
                PORTStepper2 |= (1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 2 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 |= (1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 3 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 |= (1 << PStepper2_2);
                PORTStepper2 |= (1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 4 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 |= (1 << PStepper2_3);
                PORTStepper2 &= ~(1 << PStepper2_4);
                break;
            case 5 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 |= (1 << PStepper2_3);
                PORTStepper2 |= (1 << PStepper2_4);
                break;
            case 6 :
                PORTStepper2 &= ~(1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 |= (1 << PStepper2_4);
                break;
            case 7 :
                PORTStepper2 |= (1 << PStepper2_1);
                PORTStepper2 &= ~(1 << PStepper2_2);
                PORTStepper2 &= ~(1 << PStepper2_3);
                PORTStepper2 |= (1 << PStepper2_4);
                break;
            }
            _delay_us(delaytime_stepper);
        }
        a = 0;
    }
}

void steppermotor3Write(int a)
{
    while(a  == 1)
    {
        int i;
        for(i = 1; i < 8; i=i+1)
        {
            switch (i)
            {
            case 1 :
                PORTStepper3 |= (1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 2 :
                PORTStepper3 |= (1 << PStepper3_1);
                PORTStepper3 |= (1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 3 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 |= (1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 4 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 |= (1 << PStepper3_2);
                PORTStepper3 |= (1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 5 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 |= (1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 6 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 |= (1 << PStepper3_3);
                PORTStepper3 |= (1 << PStepper3_4);
                break;
            case 7 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 |= (1 << PStepper3_4);
                break;
            case 8 :
                PORTStepper3 |= (1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 |= (1 << PStepper3_4);
                break;
            }
            _delay_us(delaytime_stepper);
        }
        a = 0;
    }
    while(a  == 2)
    {
        int i;
        for(i = 8; i > 0; --i)
        {
            switch (i)
            {
            case 8 :
                PORTStepper3 |= (1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 1 :
                PORTStepper3 |= (1 << PStepper3_1);
                PORTStepper3 |= (1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 2 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 |= (1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 3 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 |= (1 << PStepper3_2);
                PORTStepper3 |= (1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 4 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 |= (1 << PStepper3_3);
                PORTStepper3 &= ~(1 << PStepper3_4);
                break;
            case 5 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 |= (1 << PStepper3_3);
                PORTStepper3 |= (1 << PStepper3_4);
                break;
            case 6 :
                PORTStepper3 &= ~(1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 |= (1 << PStepper3_4);
                break;
            case 7 :
                PORTStepper3 |= (1 << PStepper3_1);
                PORTStepper3 &= ~(1 << PStepper3_2);
                PORTStepper3 &= ~(1 << PStepper3_3);
                PORTStepper3 |= (1 << PStepper3_4);
                break;
            }
            _delay_us(delaytime_stepper);
        }
        a = 0;
    }
}

void steppermotor4Write(int a)
{
    while(a  == 1)
    {
        int i;
        for(i = 1; i < 8; i=i+1)
        {
            switch (i)
            {
            case 1 :
                PORTStepper4 |= (1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 2 :
                PORTStepper4 |= (1 << PStepper4_1);
                PORTStepper4 |= (1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 3 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 |= (1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 4 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 |= (1 << PStepper4_2);
                PORTStepper4 |= (1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 5 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 |= (1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 6 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 |= (1 << PStepper4_3);
                PORTStepper4 |= (1 << PStepper4_4);
                break;
            case 7 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 |= (1 << PStepper4_4);
                break;
            case 8 :
                PORTStepper4 |= (1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 |= (1 << PStepper4_4);
                break;
            }
            _delay_us(delaytime_stepper);
        }
        a = 0;
    }
    while(a  == 2)
    {
        int i;
        for(i = 8; i > 0; --i)
        {
            switch (i)
            {
            case 8 :
                PORTStepper4 |= (1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 1 :
                PORTStepper4 |= (1 << PStepper4_1);
                PORTStepper4 |= (1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 2 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 |= (1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 3 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 |= (1 << PStepper4_2);
                PORTStepper4 |= (1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 4 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 |= (1 << PStepper4_3);
                PORTStepper4 &= ~(1 << PStepper4_4);
                break;
            case 5 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 |= (1 << PStepper4_3);
                PORTStepper4 |= (1 << PStepper4_4);
                break;
            case 6 :
                PORTStepper4 &= ~(1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 |= (1 << PStepper4_4);
                break;
            case 7 :
                PORTStepper4 |= (1 << PStepper4_1);
                PORTStepper4 &= ~(1 << PStepper4_2);
                PORTStepper4 &= ~(1 << PStepper4_3);
                PORTStepper4 |= (1 << PStepper4_4);
                break;
            }
            _delay_us(delaytime_stepper);
        }
        a = 0;
    }
}

void Vooruit(int Steppermotortijd)
{
    int j = 0;
    while (j< Steppermotortijd)
    {
        steppermotor1Write(1);
        steppermotor2Write(1);
        steppermotor3Write(1);
        steppermotor4Write(1);
        j++;
    }
}

void Achteruit(int Steppermotortijd)
{
    int j = 0;
    while (j< Steppermotortijd)
    {
        steppermotor1Write(2);
        steppermotor2Write(2);
        steppermotor3Write(2);
        steppermotor4Write(2);
        j++;
    }
}

void Rechtsaf(int Steppermotortijd)
{
    int j = 0;
    while (j< Steppermotortijd)
    {
        steppermotor1Write(1);
        steppermotor2Write(2);
        steppermotor3Write(1);
        steppermotor4Write(2);
        j++;
    }
}

void Linksaf(int Steppermotortijd)
{
    int j = 0;
    while (j< Steppermotortijd)
    {
        steppermotor1Write(2);
        steppermotor2Write(1);
        steppermotor3Write(2);
        steppermotor4Write(1);
        j++;
    }
}
