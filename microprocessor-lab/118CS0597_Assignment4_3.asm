
;<Seperating even numbers>

jmp start

;data

;input: 10 numbers starting from 2200H
;output: even numbers in the list stored starting from 2300H 

;code
start: nop

LXI H, 2200H
LXI D, 2300H
MVI C, 0aH
BACK: MOV A, M
ANI 01H
JNZ SKIP
MOV A, M
STAX D
INX D
SKIP: INX H
DCR C
JNZ BACK

hlt