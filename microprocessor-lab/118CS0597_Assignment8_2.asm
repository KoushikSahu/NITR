
;<Smallest in array of 10 numbers>

jmp start

;data

;input: 10 numbers at 2000H-2009H
;output: smallest number at 2010H

;code
start: nop

MVI C, 0aH
LXI H, 2000H
MOV B, M
DCR C
LOOP: INX H
MOV A, M
CMP B
JNC SKIP
MOV B, A
SKIP: DCR C
JNZ LOOP
LXI H, 2010H
MOV M, B

hlt