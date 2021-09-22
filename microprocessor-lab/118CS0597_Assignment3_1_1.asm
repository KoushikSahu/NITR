
;<sum of a series of numbers with 8 bit sum>

jmp start

;data


;code
start: nop

;sum of series at 2300H

LDA 2200H
MOV C, A 
SUB A 
LXI H, 2201H 
BACK: ADD M 
INX H
DCR C 
JNZ BACK 
STA 2300H

hlt