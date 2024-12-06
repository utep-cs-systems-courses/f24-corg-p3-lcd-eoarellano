#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "stateMachines.h"

int main()
{
  P1DIR |= LED_RED;
  P1OUT |= LED_RED;

  configureClocks();
  switch_init();
  lcd_init();
  led_init();
  buzzer_init();

  enableWDTInterrupts();
  or_sr(0x8);

}
