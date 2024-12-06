#ifndef buzzer_included
#define buzzer_included

#define C6 1108.73
#define F5 739.99
#define D6 1174.66

void buzzer_init();
void buzzer_set_period(short cycles);
void halloween();
void halloween_update();

#endif // included