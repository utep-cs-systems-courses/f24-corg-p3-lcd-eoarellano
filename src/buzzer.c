#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "stateMachines.h"
#include "lcd_states.h"

void buzzer_init()
{
    /*
       Direct timer A output "TA0.1" to P2.6.
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode(); /* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7;
    P2SEL |= BIT6;
    P2DIR = BIT6; /* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
    CCR0 = cycles;
    CCR1 = cycles >> 1; /* one half cycle */
}

void halloween_2()
{
        double notes[] = {C6, G6, B6, F6, C6, G6, B6, F6, C6, G6, B6, F6,};

        int total_notes = sizeof(notes) / sizeof(notes[0]);

        for (int i = 0; i < total_notes; i++)
        {
            buzzer_set_period(notes[i]);
            __delay_cycles(3500000);
            buzzer_set_period(0);
            __delay_cycles(3500000);
        }
        buzzer_set_period(0);
}

void halloween()
{
    double notes[] = {C6, F5, F5, D6, F5, C6, F5, F5, C6, F5, F5, D6, F5, C6, F5, F5, C6, F5, F5, D6, F5};

    int total_notes = sizeof(notes) / sizeof(notes[0]);

    for (int i = 0; i < total_notes; i++)
    {
        buzzer_set_period(notes[i]);
        __delay_cycles(2500000);
        buzzer_set_period(0);
        __delay_cycles(1000000);
    }
    buzzer_set_period(0);
}
void buzzer_off()
{
    CCR0 = 0;
    CCR1 = 0;
}

void buzzer_siren()
{
    int i = 5000;
    while(i > 0)
    {
        i -= 20;
        buzzer_set_period(i);
    }
}