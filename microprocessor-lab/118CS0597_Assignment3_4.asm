
;<largest number from a series of 8 bit numbers>

jmp start

;data


;code
start: nop

;array size in 2200H
;array content in following address starting from 2201H
;answer at 2300H

LXI H, 2200H
MOV C, M
INX H
MOV B, M
DCR C
LOOP: INX H
MOV A, M
CMP B
JC SKIP
MOV B, A
SKIP: DCR C
JNZ LOOP
LXI H, 2300H
MOV M, B

hlt