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
        green_led_on(); // waits for button to be pressed
        buzzer_off();
        break;
    case 2:
        both_leds_off();
        newBodyColor = COLOR_WHITE;
        newEyeColor = COLOR_CYAN;
        clearScreen(COLOR_BLACK);
        draw_pumpkin(newBodyColor, newEyeColor);
        halloween();    // plays halloween song
        break;
    case 3:
        newBodyColor = COLOR_GREEN;
        newEyeColor = COLOR_AQUAMARINE;
        clearScreen(COLOR_ORANGE);
        draw_pumpkin(newBodyColor, newEyeColor);
        red_led_on();
        halloween_2();   // plays halloween_2 song
        break;
    case 4:
        both_leds_off();
        lcd_siren(); // lcd siren
        break;
    }
}