
;<Moving 10 bytes from 100H to 200H>

jmp start

;data

;input: 10 bytes starting from 100H
;output: 10 bytes starting from 200H

;code
start: nop

MVI C, 0aH
LXI H, 0100H
LXI D, 0200H
LOOP: MOV A, M
STAX D
INX H
INX D
DCR C
JNZ LOOP

hlt