
.arch msp430g2553
.p2align 1,0

.text
.align 2
.global buzzer_siren
.extern buzzer_set_period

buzzer_siren:

mov #5000, r4       ; Initialize i to 5000

Top:
cmp #0, r4          ; Compare i with 0
jn Done            ; If i == 0, jump to Done

sub #20, r4         ; Subtract 20 from i
mov r4, r12         ; Move i to r12 (argument for buzzer_set_period)
call #buzzer_set_period ; Call buzzer_set_period

jmp Top            ; Jump back to Loop

Done:
ret                 ; Return from function