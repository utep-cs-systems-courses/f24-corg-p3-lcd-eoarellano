#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd_states.h"
#include "buzzer.h"
#include "led.h"
#include "stateMachines.h"

int update_pumpkin = 0;
int lcd_red = 1;
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

void draw_pumpkin(unsigned int newBodyColor, unsigned int newEyeColor)
{
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    drawString5x7(20, 40, "SPoOoOoOoOoOoOkY", COLOR_WHITE, COLOR_BLACK);

    // Pumpkin body
    fillRectangle(centerX - 25, centerY - 25, 50, 50, newBodyColor);

    // Facial features
    fillRectangle(centerX - 12, centerY + 10, 20, 10, newEyeColor); // Mouth
    fillRectangle(centerX - 15, centerY - 10, 10, 10, newEyeColor); // Left eye
    fillRectangle(centerX + 5, centerY - 10, 10, 10, newEyeColor);  // Right eye
    fillRectangle(centerX - 5, centerY, 10, 10, newEyeColor);       // Nose
}

unsigned int bodyColor = COLOR_ORANGE;
unsigned int eyeColor = COLOR_BLACK;

void update_screen(int state)
{
    if (state)
    {
        update_pumpkin = 1;
        draw_pumpkin(bodyColor, eyeColor);
    }
}
