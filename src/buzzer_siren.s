
.arch msp430g2553
.p2align 1,0

.text
.align 2
.global buzzerSiren
.extern buzzer_set_period

buzzerSiren:
sub 


Top:


Done:
pop r0

void buzzer_siren()
{
    int i = 5000;
    while(i > 0)
    {
        i -= 20;
        buzzer_set_period(i);
    }
}