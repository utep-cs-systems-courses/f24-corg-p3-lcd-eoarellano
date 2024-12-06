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

int led_on = 0;


void siren_update()
{
  if (led_on){
    P1OUT &= ~LED_GREEN;
    P1OUT |= LED_RED;
    buzzer_set_period(1000);
    led_on = 0;
  }else{
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    buzzer_set_period(2000);
    led_on = 1;
  }
}

void siren()
{
  static int count = 0;
  count++;
  if (count == 100)
  {
    siren_update();
    count = 0;
  }
}