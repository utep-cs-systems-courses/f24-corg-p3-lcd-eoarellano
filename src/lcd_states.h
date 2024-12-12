#ifndef LCD_STATES_H
#define LCD_STATES_H

void lcd_start();
void lcd_halloween();
void lcd_siren();
void lcd_siren_update();
void lcd_green();
void draw_pumpkin();
void update_screen(int state);

extern int orangePumpkin;

#endif // LCD_STATES_H