
;<Sum of series of numbers 8 bit>

jmp start

;data


;code
start: nop

;16 bit sum at 2300H and 2301H
;higher order bits at 2301H
;lower order bits at 2300H

LDA 2200H
MOV C, A
LXI H, 2201H
SUB A
MOV B, A
BACK: ADD M
JNC SKIP
INR B
SKIP: INX H
DCR C
JNZ BACK
STA 2300H
MOV A, B
STA 2301H

hlt