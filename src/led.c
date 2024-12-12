#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

void led_init()
{
    P1DIR |= LEDS;
    P1OUT &= ~LED_RED;
    P1OUT &= ~LED_GREEN;
}

void both_leds_on()
{
    P1OUT |= LED_RED;
    P1OUT |= LED_GREEN;
}

void red_led_on()
{
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
}

void green_led_on()
{
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
}
void both_leds_off()
{
    P1OUT &= ~LEDS;
}
