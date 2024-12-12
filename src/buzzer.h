#ifndef buzzer_included
#define buzzer_included

#define C6 1108.73
#define F5 739.99
#define D6 1174.66
#define G6 1567.98
#define B6 1975.53
#define F6 1479.98
#define C5 523.25

void buzzer_init();
void buzzer_set_period(short cycles);
void halloween();
void halloween_2();
void buzzer_off();
void buzzer_starting();

#endif // included