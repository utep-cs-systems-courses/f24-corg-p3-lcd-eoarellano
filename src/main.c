#include <msp430.h>
#include <stdio.h>
#include <libTimer.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachines.h"
#include "lcd_states.h"

extern int redrawScreen;
int redrawScreen;
int state;

int main(void)
{
  configureClocks();
  led_init();
  lcd_init();
  switch_init();
  buzzer_init();

  enableWDTInterrupts();
  or_sr(0x8);
  clearScreen(COLOR_BLACK);
  draw_pumpkin(COLOR_ORANGE, COLOR_BLACK);
  state = 1;
  while (1)
  {
    if (redrawScreen)
    {
      redrawScreen = 0;
      update_screen(state);
    }
    state_advance();
    P1OUT &= ~LED_RED;
    or_sr(0x10);
    P1OUT |= LED_RED;
  }
}

void wdt_c_handler()
{
  static int count = 0;
  if (update_pumpkin)
  {
    count++;
    if (count == 1250)
    {
      update_pumpkin = 0;
      count = 0;
      redrawScreen = 1;
    }
  }
  return;
}
