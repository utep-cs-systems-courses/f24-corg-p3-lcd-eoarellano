#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);  // if switch up, sense falling edge
  P2IES &= (p2val | ~SWITCHES); // if switch down, sense rising edge
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;  /* enables resistors for switches */
  P2IE |= SWITCHES;   /* enable interrupts from switches */
  P2OUT |= SWITCHES;  /* pull-ups for switches */
  P2DIR &= ~SWITCHES; /* set switches' bits for input */
  switch_update_interrupt_sense();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  char sw1 = (p2val & SW1) ? 0 : SW1;
  char sw2 = (p2val & SW2) ? 0 : SW2;
  char sw3 = (p2val & SW3) ? 0 : SW3;
  char sw4 = (p2val & SW4) ? 0 : SW4;

  if (sw1)
  {
    state_advance(1);
  }
  else if (sw2)
  {
    state_advance(2);
  }
  else if (sw3)
  {
    state_advance(3);
  }
  else if (sw4)
  {
   state_advance(4);
  }
}

void __interrupt_vec(PORT2_VECTOR) Port_2()
{
  if (P2IFG & SWITCHES)
  {                             // Check if any switch was pressed
    P2IFG &= ~SWITCHES;         // Clear interrupt flag
    switch_interrupt_handler(); // Handle switch interrupt
  }
}