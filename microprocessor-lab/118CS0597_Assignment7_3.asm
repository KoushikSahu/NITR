
;<Add only even numbers from array of 10 numbers>

jmp start

;data

;Input: Ten 8-bit numbers from 2000H - 2009H
;Output: Sum of even numbers at 2010H

;code
start: nop

MVI C, 0aH
MVI B, 00H
LXI H, 2000H
STMT: MOV A, M
ANI 01H
JNZ SKIP
MOV A, B
ADD M
MOV B, A
SKIP: INX H
DCR C
JNZ STMT
MOV A, B
STA 2010H

hlt