
;<Fibonacci series>

jmp start

;data

;input: no input
;output: fibonacci series produced starting from address 2000H

;code
start: nop

LXI H, 2000H
MVI C, 08H
MVI B, 00H
MVI D, 01H
MOV M, B
INX H
MOV M, D
stmt: MOV A, B
ADD D
MOV B, D
MOV D, A
INX H
MOV M, A
DCR C
JNZ stmt

hlt