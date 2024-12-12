#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd_states.h"

void state_advance(int state)
{
    unsigned int newBodyColor;
    unsigned int newEyeColor;
    switch (state)
    {
    case 1:
        update_pumpkin = 0;
        clearScreen(COLOR_BLACK);
        green_led_on(); // waits for button to be pressed
        buzzer_off();
        break;
    case 2:
        newBodyColor = COLOR_WHITE;
        newEyeColor = COLOR_CYAN;
        draw_pumpkin(newBodyColor, newEyeColor);
        halloween();    // plays halloween song
        break;
    case 3:
        newBodyColor = COLOR_GREEN;
        newEyeColor = COLOR_AQUAMARINE;
        draw_pumpkin(newBodyColor, newEyeColor);
        both_leds_off(); // both leds off
        halloween_2();   // plays halloween_2 song
        break;
    case 4:
        update_pumpkin = 0;
        lcd_siren(); // lcd siren
        break;
    }
}