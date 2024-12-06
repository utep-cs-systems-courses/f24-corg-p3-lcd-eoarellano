#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd_states.h"
#include "buzzer.h"
#include "led.h"

void lcd_start()
{
    clearScreen(COLOR_BLUE);
    drawString5x7(20,20, "Welcome", COLOR_WHITE, COLOR_BLUE);
    fillRectangle(30, 30, 60, 60, COLOR_BLACK);
}

void lcd_halloween()
{
    clearScreen(COLOR_BLACK);
    drawString5x7(40,50, "Happy Halloween", COLOR_WHITE, COLOR_ORANGE);
    fillRectangle(30, 30, 60, 60, COLOR_CYAN);
}

int lcd_red = 0;

void lcd_siren()
{
    if (lcd_red)
    {
        clearScreen(COLOR_RED);
        buzzer_set_period(2000);
        lcd_red = 0;
        
    }
    else
    {
        clearScreen(COLOR_BLUE);
        buzzer_set_period(1000);
        lcd_red = 1;
    }
}

void lcd_siren_update()
{
  static int count = 0;
  count++;
  if (count == 100)
  {
    lcd_siren();
    count = 0;
  }
}