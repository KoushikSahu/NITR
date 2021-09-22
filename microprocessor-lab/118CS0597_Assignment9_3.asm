
;<Moving 10 bytes from 100H to 105H>

jmp start

;data

;input: 10 bytes starting from 100H
;output: 10 bytes starting from 105H

;code
start: nop

MVI C, 0aH
LXI H, 0100H
LXI D, 0200H
LOOP1: MOV A, M
STAX D
INX H
INX D
DCR C
JNZ LOOP1
MVI C, 0aH
LXI H, 0200H
LXI D, 0105H
LOOP2: MOV A, M
STAX D
INX H
INX D
DCR C
JNZ LOOP2

hlt