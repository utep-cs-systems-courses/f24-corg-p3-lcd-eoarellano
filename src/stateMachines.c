#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd_states.h"

int state = 0;

void state_advance()
{   
    switch (state)
    {
    case 1:
        both_leds_on();
        break;
    case 2:
        red_led_on();
        
        break;
    case 3:
        //wdt handles siren
        break;
    case 4:
        green_led_on();
        break;
    }
}

void __interrupt_vec(WDT_VECTOR) WDT()
{
    if (state == 3)
    {
        lcd_siren_update();
    }
    if (state == 4)
    {
        halloween_update();
    }
    else 
    {
        state_advance();
    }
}